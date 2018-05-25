[%bs.raw {|require('./styles/index.scss')|}];

[@bs.val] external window : Dom.window = "window";

[@bs.scope "window"] [@bs.val]
external initial_state : Js.Json.t = "__INITIAL_STATE__";

let todos = initial_state |> Api.decodeTodos;

ReactDOMRe.hydrateToElementWithId(<App initialState=todos />, "root");

ReasonReact.Router.push("");