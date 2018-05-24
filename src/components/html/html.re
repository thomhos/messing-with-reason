let component = ReasonReact.statelessComponent("Html");

let make = children => {
  ...component,
  render: _self =>
    <html>
      <head>
        <title> (ReasonReact.string("Hello world")) </title>
        <link rel="stylesheet" href="client.css" />
      </head>
      <body>
        (
          ReasonReact.createDomElement("div", ~props={"id": "root"}, children)
        )
        <script src="client.js" />
      </body>
    </html>,
};