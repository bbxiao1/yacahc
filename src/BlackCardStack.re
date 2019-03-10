let component = ReasonReact.statelessComponent("BlackCardStack");

/* greeting and children are props. `children` isn't used, therefore ignored.
   We ignore it by prepending it with an underscore */
let make = (~shuffled, _children) => {
  ...component,
  render: _self => {
    let currentCard = List.hd(Array.to_list(shuffled));
    <div>
      <Card text=currentCard color=Card.Black />
    </div>;
  },
};
