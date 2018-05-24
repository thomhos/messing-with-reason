type route =
  | Home
  | List
  | ListItem(string)
  | NotFound;

type state = route;

type action =
  | ChangeRoute(route);

let mapUrlToRoute = (url: ReasonReact.Router.url) =>
  switch (url.path) {
  | [] => Home
  | ["list"] => List
  | ["list", id] => ListItem(id)
  | _ => NotFound
  };

let component = ReasonReact.reducerComponent("Router");

let make = (~initialUrl: option(string), children) => {
  ...component,
  initialState: () =>
    switch (initialUrl) {
    | Some(url) => url |> Utils.createUrlFromString |> mapUrlToRoute
    | None => ReasonReact.Router.dangerouslyGetInitialUrl() |> mapUrlToRoute
    },
  reducer: (action, _state) =>
    switch (action) {
    | ChangeRoute(route) => ReasonReact.Update(route)
    },
  didMount: ({send, onUnmount}) => {
    let watcherId =
      ReasonReact.Router.watchUrl(url =>
        send(ChangeRoute(url |> mapUrlToRoute))
      );
    onUnmount(() => ReasonReact.Router.unwatchUrl(watcherId));
  },
  render: ({state}) => children(~route=state),
};