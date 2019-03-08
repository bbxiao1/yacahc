let card = ReasonReact.statelessComponent("Card");

type color = White | Black;

/* Your familiar handleClick from ReactJS. This mandatorily takes the payload,
   then the `self` record, which contains state (none here), `handle`, `reduce`
   and other utilities */
let handleClick = (_event, _self) => Js.log("clicked!");

/* `make` is the function that mandatorily takes `children` (if you want to use
   `JSX). `message` is a named argument, which simulates ReactJS props. Usage:

   `<Component1 message="hello" />`

   Which desugars to

   `ReasonReact.element(Component1.make(~message="hello", [||]))` */
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
