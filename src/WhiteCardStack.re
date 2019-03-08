type stats = {
  activeCards: list(string)
}

type action = Deal;

let component = ReasonReact.reducerComponent("WhiteCardStack");
let make = (~shuffled, _children) => {
  ...component,
  initialState: () => {
    {activeCards: Array.to_list(shuffled)}
  },

  /* State transitions */
  reducer: (action, state) =>
    switch (action) {
    | Deal => ReasonReact.Update({activeCards: List.tl(state.activeCards)})
    },

  render: self => {
    let currentCard = List.hd(self.state.activeCards);
    <div style=ReactDOMRe.Style.make(~marginTop="10px", ())>
      <Card text=currentCard color=Card.White />
      <button onClick={_event => self.send(Deal)}>
        {ReasonReact.string("Deal")}
      </button>
    </div>;
  },
}
