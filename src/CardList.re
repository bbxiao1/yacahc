let cardList = ReasonReact.statelessComponent("CardList");
let make = (~allText, ~color, _children) => {
    ...cardList,
    render: _self =>{
      let cards = Array.map((text) => {
          <Card text=text color=color />
        }, allText);
      <div>
        (ReasonReact.array(cards))
      </div>
    }
}
