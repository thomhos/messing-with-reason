let component = ReasonReact.statelessComponent("Overview");

let make = (~todos: Todos.state, _children) => {
  ...component,
  didMount: _self => {
    Js.log("Some todos");
    Js.log(todos);
  },
  render: _self => <div> (ReasonReact.string("Overview")) </div>,
};