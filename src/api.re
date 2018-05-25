type todo = {
  id: int,
  description: string,
  completed: bool,
};

let encodeTodos = tds =>
  tds
  |> Array.of_list
  |> Json.Encode.array(t =>
       Json.Encode.object_([
         ("id", t.id |> Json.Encode.int),
         ("description", t.description |> Json.Encode.string),
         ("completed", t.completed |> Json.Encode.bool),
       ])
     )
  |> Js.Json.stringify;

let decodeTodos = tds =>
  tds
  |> Json.Decode.array(t =>
       Json.Decode.{
         id: t |> field("id", int),
         description: t |> field("description", string),
         completed: t |> field("completed", bool),
       }
     )
  |> Array.to_list;

let fetchSomeTodos =
  Js.Promise.make((~resolve, ~reject as _) => {
    let todos: list(todo) = [
      {id: 0, description: "Lorem ipsum fooo", completed: false},
      {id: 1, description: "Lorem ipsum fooo", completed: true},
      {id: 2, description: "Lorem ipsum fooo", completed: false},
      {id: 3, description: "Lorem ipsum fooo", completed: false},
      {id: 4, description: "Lorem ipsum fooo", completed: false},
    ];
    resolve(. todos);
  });