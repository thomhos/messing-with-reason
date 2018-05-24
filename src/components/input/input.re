let component = ReasonReact.statelessComponent("Input");

let make = (~_type, ~onChange, ~value=?, _children) => {
  ...component,
  render: _self => <input className="input" _type onChange ?value />,
};