[%bs.raw {|require('./styles/index.scss')|}];

ReactDOMRe.hydrateToElementWithId(<App />, "root");

ReasonReact.Router.push("");

Js.log("hello from client");