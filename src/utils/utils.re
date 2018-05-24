let parseUrlPath = url =>
  switch (url) {
  | ""
  | "/" => []
  | _ =>
    /* remove the preceeding /, which every pathname seems to have */
    let raw = Js.String.sliceToEnd(~from=1, url);
    /* remove the trailing /, which some pathnames might have. Ugh */
    let raw =
      switch (Js.String.get(raw, Js.String.length(raw) - 1)) {
      | "/" => Js.String.slice(~from=0, ~to_=-1, raw)
      | _ => raw
      };
    raw |> Js.String.split("/") |> Array.to_list;
  };

let createUrlFromString = (initialUrl: string) : ReasonReact.Router.url => {
  path: parseUrlPath(initialUrl),
  hash: "",
  search: "",
};