type state = list(Api.todo);

type action =
  | Add(Api.todo)
  | Complete(int)
  | Remove(int);

let component = ReasonReact.reducerComponent("App");

let make = (~initialUrl=?, ~initialState: state, _children) => {
  ...component,
  initialState: () => initialState,
  reducer: (action, state) =>
    switch (action) {
    | Add(todo) => ReasonReact.Update(List.append(state, [todo]))
    | Complete(int) => ReasonReact.Update(state)
    | Remove(int) => ReasonReact.Update(state)
    },
  render: ({state}) =>
    <Router initialUrl>
      ...(
           (~route) =>
             switch (route) {
             | Overview => <Overview todos=state />
             | Detail(id) => <Detail id />
             | NotFound => <NotFound />
             }
         )
    </Router>,
};
/* didMount: _self =>
   Api.fetchSomePosts
   |> Js.Promise.then_(posts => {
        let first: Api.post = List.nth(posts, 1);
        Js.log(first.title);
        Js.log(
          switch (posts) {
          | [] => "list is empty"
          | rest =>
            "list has length of " ++ string_of_int(List.length(rest))
          },
        );
        Js.Promise.resolve();
      })
   |> Js.Promise.catch(error => {
        Js.log(error);
        Js.Promise.resolve();
      })
   |> ignore, */