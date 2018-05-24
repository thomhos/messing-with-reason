let make = (~content, ~title, ~stylesheet, ~script, ()) => {j|
    <!DOCTYPE html>
      <html>
        <head>
          <title>$title</title>
          <link rel="stylesheet" href="$stylesheet" />
          </head>
          <body>
          <div id="root">$content</div>
          <script src="$script"></script>
        </body>
      </html>
  |j};