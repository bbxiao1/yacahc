type game = {
  players: list(Player.player),
  blackStack: CardStack.stack,
  whiteStack: CardStack.stack,
  currentPlayer: int,
}

type state = {
  game: game,
  newPlayerName: string,
  nextId: int,
}

type action =
  | AddPlayer(string)
  | NextCard;

let component = ReasonReact.reducerComponent("Coordinator");
let make = (~blackCards, ~whiteCards, _children) => {
  ...component,
  initialState: () => {
    {
      game: {
        players: [],
        blackStack: {available: blackCards, color: Card.Black},
        whiteStack: {available: whiteCards, color: Card.White},
        currentPlayer: 0
      },
      newPlayerName: "",
      nextId: 1
    }
  },
  reducer: (action, state) => {
    switch (action) {
    | AddPlayer(name) => {
        let newPlayer = {id: state.nextId, name: name, availableCards: [], points: 0};
        let players = List.append(state.game.players, [newPlayer]);
        ReasonReact.Update({...state, game: {...game, players: players}});
      }
    | NextCard => {
        let stack = List.tl(state.blackStack.available);
        ReasonReact.Update({...state, game: {...game, blackStack: stack}});
      }
    };
  },
  render: self => {
    let currentCard = List.hd(self.state.game.blackStack.available);
    let players = Array.map((p) => {
      <Player key=string_of_int(Player.(p.id)) player=p />
    }, Array.of_list(self.state.game.players));
    <div>
      <Card text=currentCard color=Card.Black />
      {ReasonReact.array(players)}
      <form>
        <input placeholder="New Player Name" value=self.state >

        </input>
      </form>
    </div>;
  }
}
