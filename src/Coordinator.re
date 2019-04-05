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
  | ChangePlayerName(string)
  | AddPlayer(string)
  | NextCard;

let component = ReasonReact.reducerComponent("Coordinator");
let make = (~blackCards, ~whiteCards, _children) => {
  let rec take = (list, n, accum) => {
    switch (n) {
    | 0 => (accum, list)
    | _ => take(List.tl(list), n, List.append(accum, [List.hd(list)]))
    }
  };
  {
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
      | ChangePlayerName(name) => ReasonReact.Update({...state, newPlayerName: name})
      | AddPlayer(name) => {
          let (newCards, remaining) = take(state.game.whiteStack.available, 7, [])
          let newPlayer = {Player.id: state.nextId, name: name, availableCards: newCards, points: 0};
          let players = List.append(state.game.players, [newPlayer]);
          ReasonReact.Update({game: {...state.game, players: players, whiteStack: {...state.game.whiteStack, available: remaining}}, newPlayerName: "", nextId: state.nextId + 1});
        }
      | NextCard => {
          let blackStack = state.game.blackStack;
          let available = List.tl(blackStack.available);
          ReasonReact.Update({...state, game: {...state.game, blackStack: {...blackStack, available: available}}});
        }
      };
    },
    render: ({state, send}) => {
      let currentCard = List.hd(state.game.blackStack.available);
      let players = Array.map((p) => {
        <Player key=string_of_int(Player.(p.id)) player=p />
      }, Array.of_list(state.game.players));
      <div>
        <Card text=currentCard color=Card.Black />
        <br />
        <form>
          <input placeholder="New Player Name" value=state.newPlayerName onChange=(event => send(ChangePlayerName(ReactEvent.Form.target(event)##value))) >
          </input>
          <button onClick=(event => {ReactEvent.Mouse.preventDefault(event); send(AddPlayer(state.newPlayerName))})>
            {ReasonReact.string("Create Player")}
          </button>
        </form>
        <br />
        {ReasonReact.array(players)}
      </div>;
    }
  }
}
