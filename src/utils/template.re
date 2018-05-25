let make = (~content, ~title, ~stylesheet, ~script, ~initialState: string, ()) => {
  let stateTag = {j|<script>window.__INITIAL_STATE__ = $initialState;</script>|j};
  {j|
    <!DOCTYPE html>
      <html>
        <head>
          <title>$title</title>
          <link rel="stylesheet" href="$stylesheet" />
          </head>
          <body>
          <div id="root">$content</div>
          $stateTag
          <script src="$script"></script>
        </body>
      </html>
  |j};
};