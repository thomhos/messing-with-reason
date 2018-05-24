let component = ReasonReact.statelessComponent("App");

let make = (~initialUrl=?, _children) => {
  ...component,
  didMount: _self => Js.log("hello"),
  render: _self =>
    <Router initialUrl>
      ...(
           (~route) =>
             switch (route) {
             | Home => <Home />
             | List => <List />
             | ListItem(id) => <ListItem id />
             | NotFound => <NotFound />
             }
         )
    </Router>,
};