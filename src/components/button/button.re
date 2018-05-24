let component = ReasonReact.statelessComponent("Button");

let make = (~onClick=?, children) => {
  ...component,
  render: _self =>
    <button className="mybutton" ?onClick>
      <span> (ReasonReact.array(children)) </span>
    </button>,
};