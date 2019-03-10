let card = ReasonReact.statelessComponent("Card");

type color = White | Black;

let handleClick = (_event, _self) => Js.log("clicked!");

let make = (~text, ~color, _children) => {
  ...card,
  render: _self => {
    let style = switch (color){
                | White => ReactDOMRe.Style.make(~width="18rem", ~height="22rem", ~margin="5px", ())
                | Black => ReactDOMRe.Style.make(~width="18rem", ~height="22rem", ~margin="5px", ~backgroundColor="black", ~color="white", ())
                };
    <div className="card" style=style>
      <div className="card-body">
        <div className="card-text">
          {ReasonReact.string(text)}
        </div>
      </div>
    </div>
  },
};
