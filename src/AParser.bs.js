// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE
'use strict';

var Utils$Repaco = require("./Utils.bs.js");

function aParser(str) {
  var xs = Utils$Repaco.string_to_list(str);
  if (xs) {
    if (xs[0] === "A") {
      return /* tuple */[
              true,
              Utils$Repaco.list_to_string(xs[1])
            ];
    } else {
      return /* tuple */[
              false,
              str
            ];
    }
  } else {
    return /* tuple */[
            false,
            ""
          ];
  }
}

exports.aParser = aParser;
/* No side effect */
