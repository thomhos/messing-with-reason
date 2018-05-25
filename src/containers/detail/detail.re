let component = ReasonReact.statelessComponent("Detail");

let make = (~id, _children) => {
  ...component,
  render: _self => <div> (ReasonReact.string("Detail: " ++ id)) </div>,
};