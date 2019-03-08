// Generated by BUCKLESCRIPT VERSION 4.0.18, PLEASE EDIT WITH CARE
'use strict';

var List = require("bs-platform/lib/js/list.js");
var ReactDOMRe = require("reason-react/src/ReactDOMRe.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var CardList$ReactTemplate = require("./CardList.bs.js");

List.iter((function (param) {
        var id = param[2];
        var color = param[1];
        fetch(param[0]).then((function (prim) {
                    return prim.text();
                  })).then((function (text) {
                  return Promise.resolve(text.split("\n"));
                })).then((function (texts) {
                return Promise.resolve(ReactDOMRe.renderToElementWithId(ReasonReact.element(undefined, undefined, CardList$ReactTemplate.make(texts, color, /* array */[])), id));
              }));
        return /* () */0;
      }), /* :: */[
      /* tuple */[
        "/assets/black.txt",
        /* Black */1,
        "black"
      ],
      /* :: */[
        /* tuple */[
          "/assets/white.txt",
          /* White */0,
          "white"
        ],
        /* [] */0
      ]
    ]);

/*  Not a pure module */
