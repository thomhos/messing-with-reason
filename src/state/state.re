type state = {todos: Todos.state};

type action =
  | Todos(Todos.action);

let initialState = () => {todos: Todos.initialState()};

let reducer = (action, state) =>
  switch (action) {
  | Todos(todoAction) =>
    ReasonReact.Update({todos: Todos.reducer(todoAction, state.todos)})
  };