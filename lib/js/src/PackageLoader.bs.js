// Generated by BUCKLESCRIPT VERSION 3.0.0, PLEASE EDIT WITH CARE
'use strict';

var List = require("bs-platform/lib/js/list.js");
var $$Array = require("bs-platform/lib/js/array.js");
var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var Js_mapperRt = require("bs-platform/lib/js/js_mapperRt.js");
var ReasonReact = require("reason-react/lib/js/src/ReasonReact.js");

var jsMapperConstantArray = /* array */[
  /* tuple */[
    -162577412,
    "upcoming"
  ],
  /* tuple */[
    422888473,
    "current"
  ]
];

function versionToJs(param) {
  return Js_mapperRt.binarySearch(2, param, jsMapperConstantArray);
}

function versionFromJs(param) {
  return Js_mapperRt.revSearch(2, jsMapperConstantArray, param);
}

var jsMapperConstantArray$1 = /* array */[
  /* tuple */[
    -763086433,
    "table"
  ],
  /* tuple */[
    3303859,
    "bar"
  ],
  /* tuple */[
    504440814,
    "table"
  ],
  /* tuple */[
    777774847,
    "corechart"
  ]
];

function packageToJs(param) {
  return Js_mapperRt.binarySearch(4, param, jsMapperConstantArray$1);
}

function packageFromJs(param) {
  return Js_mapperRt.revSearch(4, jsMapperConstantArray$1, param);
}

var component = ReasonReact.reducerComponent("GoogleChart");

function make(version, packages, children) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */(function (self) {
              google.charts.load(versionToJs(version), {
                    packages: $$Array.of_list(List.map(packageToJs, packages))
                  });
              google.charts.setOnLoadCallback((function (_, _$1) {
                      return Curry._1(self[/* send */3], /* OnLoad */0);
                    }));
              return /* () */0;
            }),
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (self) {
              return Curry._1(children, self[/* state */1][/* remote */0]);
            }),
          /* initialState */(function () {
              return /* record */[/* remote : Loading */0];
            }),
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */(function (_, _$1) {
              return /* Update */Block.__(0, [/* record */[/* remote : Success */1]]);
            }),
          /* subscriptions */component[/* subscriptions */13],
          /* jsElementWrapped */component[/* jsElementWrapped */14]
        ];
}

exports.versionToJs = versionToJs;
exports.versionFromJs = versionFromJs;
exports.packageToJs = packageToJs;
exports.packageFromJs = packageFromJs;
exports.component = component;
exports.make = make;
/* component Not a pure module */