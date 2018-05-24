let component = ReasonReact.statelessComponent("ListItem");

let make = (~id, _children) => {
  ...component,
  render: _self => <div> (ReasonReact.string("ListItem: " ++ id)) </div>,
};