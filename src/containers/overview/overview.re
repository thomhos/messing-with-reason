type state = {draftTodo: string};

type action =
  | ChangeDraft(string);

let component = ReasonReact.reducerComponent("Overview");

let make =
    (~todos: list(Api.todo), ~addTodo, ~completeTodo, ~removeTodo, _children) => {
  ...component,
  initialState: () => {draftTodo: ""},
  reducer: (action, _state) =>
    switch (action) {
    | ChangeDraft(value) => ReasonReact.Update({draftTodo: value})
    },
  render: ({send, state}) =>
    <div>
      <h1> (ReasonReact.string("Overview")) </h1>
      <hr />
      <input
        _type="text"
        value=state.draftTodo
        onChange=(e => send(ChangeDraft(Utils.valueFromEvent(e))))
      />
      <button
        onClick=(
          _e => {
            addTodo(state.draftTodo);
            send(ChangeDraft(""));
          }
        )>
        (ReasonReact.string("Add"))
      </button>
      <hr />
      <div>
        (
          todos
          |> Array.of_list
          |> Array.map((todo: Api.todo) =>
               <div key=(todo.id |> string_of_int)>
                 <input
                   _type="checkbox"
                   checked=todo.completed
                   onChange=(_e => completeTodo(todo.id))
                 />
                 <span> (ReasonReact.string(todo.description)) </span>
                 <button onClick=(_e => removeTodo(todo.id))>
                   (ReasonReact.string("Remove"))
                 </button>
               </div>
             )
          |> ReasonReact.array
        )
      </div>
    </div>,
};