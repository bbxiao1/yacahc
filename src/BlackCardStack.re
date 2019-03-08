/* State declaration */
type state = {
  activeCards: list(string)
};

/* Action declaration */
type action = Click;

/* Component template declaration.
   Needs to be **after** state and action declarations! */
let component = ReasonReact.reducerComponent("BlackCardStack");

/* greeting and children are props. `children` isn't used, therefore ignored.
   We ignore it by prepending it with an underscore */
let make = (~shuffled, _children) => {
  ...component,
  initialState: () => {
    {activeCards: Array.to_list(shuffled)}
  },

  /* State transitions */
  reducer: (action, state) =>
    switch (action) {
    | Click => ReasonReact.Update({activeCards: List.tl(state.activeCards)})
    },

  render: self => {
    let currentCard = List.hd(self.state.activeCards);
    <div>
      <Card text=currentCard color=Card.Black />
      <button onClick={_event => self.send(Click)}>
        {ReasonReact.string("Next Card")}
      </button>
    </div>;
  },
};
