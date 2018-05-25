type state = list(Api.todo);

type action =
  | Add(string)
  | Complete(int)
  | Remove(int);

let component = ReasonReact.reducerComponent("App");

let make = (~initialUrl=?, ~initialState: state, _children) => {
  ...component,
  initialState: () => initialState,
  reducer: (action, state) =>
    switch (action) {
    | Add(description) =>
      ReasonReact.Update(
        List.append(
          state,
          [{id: List.length(state), description, completed: false}],
        ),
      )
    | Complete(id) =>
      ReasonReact.Update(
        state
        |> List.map((t: Api.todo) =>
             t.id === id ? {...t, completed: ! t.completed} : t
           ),
      )
    | Remove(id) =>
      ReasonReact.Update(state |> List.filter((t: Api.todo) => t.id != id))
    },
  render: ({state, send}) =>
    <Router initialUrl>
      ...(
           (~route) =>
             switch (route) {
             | Overview =>
               <Overview
                 todos=state
                 addTodo=(todo => send(Add(todo)))
                 completeTodo=(id => send(Complete(id)))
                 removeTodo=(id => send(Remove(id)))
               />
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