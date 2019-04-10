type player = {
  id: int,
  availableCards: list(string),
  points: int,
  name: string,
}

type action =
  | Select
  | Submit;

let component = ReasonReact.statelessComponent("Player");

let make = (~update, ~player, _children) => {
  ...component,
  render: _self => {
    let cards = Array.map((c) => {
      <Card text=c update color=Card.White />
    }, Array.of_list(player.availableCards));
    <div>
      <strong>{ReasonReact.string(player.name)}</strong><br />
      <div style={ReactDOMRe.Style.make(~display="flex", ~flexWrap="wrap", ())}>
        {ReasonReact.array(cards)}
      </div>
    </div>;
  },
}
