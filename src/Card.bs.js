// Generated by BUCKLESCRIPT VERSION 4.0.18, PLEASE EDIT WITH CARE
'use strict';

var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");

var card = ReasonReact.statelessComponent("Card");

function handleClick(_event, _self) {
  console.log("clicked!");
  return /* () */0;
}

function make(text, color, _children) {
  return /* record */[
          /* debugName */card[/* debugName */0],
          /* reactClassInternal */card[/* reactClassInternal */1],
          /* handedOffState */card[/* handedOffState */2],
          /* willReceiveProps */card[/* willReceiveProps */3],
          /* didMount */card[/* didMount */4],
          /* didUpdate */card[/* didUpdate */5],
          /* willUnmount */card[/* willUnmount */6],
          /* willUpdate */card[/* willUpdate */7],
          /* shouldUpdate */card[/* shouldUpdate */8],
          /* render */(function (_self) {
              var style = color ? ({
                    backgroundColor: "black",
                    color: "white",
                    margin: "5px",
                    width: "18rem"
                  }) : ({
                    margin: "5px",
                    width: "18rem"
                  });
              return React.createElement("div", {
                          className: "card",
                          style: style
                        }, React.createElement("div", {
                              className: "card-body"
                            }, React.createElement("div", {
                                  className: "card-text"
                                }, text)));
            }),
          /* initialState */card[/* initialState */10],
          /* retainedProps */card[/* retainedProps */11],
          /* reducer */card[/* reducer */12],
          /* jsElementWrapped */card[/* jsElementWrapped */13]
        ];
}

exports.card = card;
exports.handleClick = handleClick;
exports.make = make;
/* card Not a pure module */
