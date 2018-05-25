let component = ReasonReact.statelessComponent("Overview");

let make = (~todos: list(Api.todo), _children) => {
  ...component,
  render: _self =>
    <div>
      <h1> (ReasonReact.string("Overview")) </h1>
      <div>
        (
          todos
          |> Array.of_list
          |> Array.map((todo: Api.todo) =>
               <div key=(todo.id |> string_of_int)>
                 (ReasonReact.string(todo.description))
               </div>
             )
          |> ReasonReact.array
        )
      </div>
    </div>,
};