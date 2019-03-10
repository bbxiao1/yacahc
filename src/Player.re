type player = {
  id: int,
  availableCards: list(string),
  points: int,
  name: string,
}

type state = {
  isActive: bool,
}

type action = Select | Submit;

let component = ReasonReact.reducerComponent("Player");

let make = (~player, _children) => {
  ...component,
  initialState: () => {isActive: false},

  reducer: (action, state) => {
    switch (action) {
    | Select => ReasonReact.Update(state);
    | Submit => ReasonReact.Update(state);
    }
  },
  render: _self => {
    <div>{ReasonReact.string(player.name)}</div>;
  },
}
