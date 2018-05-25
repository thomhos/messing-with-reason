type post = {
  title: string,
  description: string,
};

let fetchSomePosts =
  Js.Promise.make((~resolve, ~reject as _) => {
    let posts: list(post) = [
      {title: "Foo", description: "Lorem ipsum fooo"},
      {title: "Foo", description: "Lorem ipsum fooo"},
      {title: "Foo", description: "Lorem ipsum fooo"},
      {title: "Foo", description: "Lorem ipsum fooo"},
      {title: "Foo", description: "Lorem ipsum fooo"},
    ];
    resolve(. posts);
  });