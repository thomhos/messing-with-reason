let port = 3000;

let app = Express.App.make();

/* Serve static files */
Express.Static.defaultOptions()
|> Express.Static.make("dist")
|> Express.Static.asMiddleware
|> Express.App.useOnPath(app, ~path="/");

/* Render the client on all other incoming get requests */
let renderer = (_next, req, res) =>
  res
  |> Express.Response.sendString(
       {
         let initialUrl = req |> Express.Request.path;
         let content = <App initialUrl /> |> ReactDOMServerRe.renderToString;
         let title = "Hello World";
         let stylesheet = "client.css";
         let script = "client.js";
         Template.make(~content, ~title, ~stylesheet, ~script, ());
       },
     )
  |> Js.Promise.resolve;

renderer |> Express.PromiseMiddleware.from |> Express.App.get(app, ~path="*");

/* Start the server */
let onListen = e =>
  switch (e) {
  | exception (Js.Exn.Error(e)) => Js.log(e)
  | _ => Js.log("Listening on http://localhost:3000")
  };

Express.App.listen(app, ~port, ~onListen, ());