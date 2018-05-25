type todo = {
  id: int,
  description: string,
  completed: bool,
};

type state = list(todo);

type action =
  | Add(todo)
  | Complete(int)
  | Remove(int);

let initialState = () => [];

let reducer = (action, state) =>
  switch (action) {
  | Add(todo) => List.append(state, [todo])
  | Complete(int) => state
  | Remove(int) => state
  };