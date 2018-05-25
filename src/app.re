let component = ReasonReact.reducerComponent("App");

let make = (~initialUrl=?, _children) => {
  ...component,
  initialState: State.initialState,
  reducer: State.reducer,
  render: ({state}) =>
    <Router initialUrl>
      ...(
           (~route) =>
             switch (route) {
             | Overview => <Overview todos=(state: State.state).todos />
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