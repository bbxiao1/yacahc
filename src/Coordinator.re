type game = {
  players: list(Player.player),
  blackStack: CardStack.stack,
  whiteStack: CardStack.stack,
  currentPlayerId: int,
  currentRound: list((int, string))
}

type state = {
  game: game,
  newPlayerName: string,
  nextId: int,
}

type action =
  | ChangePlayerName(string)
  | AddPlayer(string)
  | NextPlayer
  | NextCard
  | CardUpdate(unit => string);

let component = ReasonReact.reducerComponent("Coordinator");
let make = (~blackCards, ~whiteCards, _children) => {
  let rec take = (list, n, accum) => {
    switch (n) {
    | 0 => (accum, list)
    | _ => take(List.tl(list), n-1, List.append(accum, [List.hd(list)]))
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
          currentPlayerId: 0,
          currentRound: []
        },
        newPlayerName: "",
        nextId: 1
      }
    },
    reducer: (action, state) => {
      switch (action) {
      | ChangePlayerName(name) => ReasonReact.Update({...state, newPlayerName: name})
      | AddPlayer(name) => {
          let (newCards, remaining) = take(state.game.whiteStack.available, 7, []);
          let newPlayer = {Player.id: state.nextId, name: name, availableCards: newCards, points: 0};
          let players = List.append(state.game.players, [newPlayer]);
          ReasonReact.Update({
            game: {
              ...state.game,
              players: players,
              whiteStack: {...state.game.whiteStack, available: remaining}
            },
            newPlayerName: "",
            nextId: state.nextId + 1
          });
        }
      | NextPlayer => ReasonReact.Update({...state, game: {...state.game, currentPlayerId: state.game.currentPlayerId + 1}});
      | NextCard => {
          let blackStack = state.game.blackStack;
          let available = List.tl(blackStack.available);
          ReasonReact.Update({...state, game: {...state.game, blackStack: {...blackStack, available: available}}});
        }
      | CardUpdate(getSelectedCard) => {
          let card = getSelectedCard();
          let currentRound = List.append(state.game.currentRound, [(state.game.currentPlayerId, card)]);
          ReasonReact.Update({...state, game: {...state.game, currentRound}});
        }
      };
    },
    render: ({state, send}) => {
      let update = (getSelectedCard) => send(CardUpdate(getSelectedCard));
      let currentCard = List.hd(state.game.blackStack.available);
      let findPlayer = (id) => {
          try (Some(List.find((p) => { Player.(p.id) == id; }, state.game.players))) {
        | Not_found => None;
        };
      }
      let currentPlayer = findPlayer(state.game.currentPlayerId);
      let playerBlock = switch (currentPlayer) {
      | None => <div></div>
      | Some(player) => <Player key=string_of_int(Player.(player.id)) update player />
      };
      let inPlayCards = Array.map(((id, card)) => {
        let player = switch (findPlayer(id)) {
        | None => ""
        | Some(player) => player.name
        };
        <div>
          <dt>{ReasonReact.string(player)}</dt>
          <dd>{ReasonReact.string(card)}</dd>
        </div>
      }, Array.of_list(state.game.currentRound));
      let hiddenStartButton = (state.game.currentPlayerId > 0) || List.length(state.game.players) == 0;
      <div>
        <Card text=currentCard update color=Card.Black />
        <br />
        <form>
          <input placeholder="New Player Name" value=state.newPlayerName onChange=(event => send(ChangePlayerName(ReactEvent.Form.target(event)##value))) >
          </input>
          <button onClick=(event => {ReactEvent.Mouse.preventDefault(event); send(AddPlayer(state.newPlayerName))})>
            {ReasonReact.string("Create Player")}
          </button>
        </form>
        <br />
        <button onClick=(event => {ReactEvent.Mouse.preventDefault(event); send(NextPlayer)}) hidden={hiddenStartButton}>
          {ReasonReact.string("Start")}
        </button>
        {playerBlock}
        <dl>{ReasonReact.array(inPlayCards)}</dl>
      </div>;
    }
  }
}
