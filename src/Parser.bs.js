// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE
'use strict';

var $$Array = require("bs-platform/lib/js/array.js");

function list_to_string(xs) {
  return $$Array.of_list(xs).join("");
}

function string_to_list(str) {
  return $$Array.to_list(str.split(""));
}

function aParser(str) {
  var xs = $$Array.to_list(str.split(""));
  console.log(xs);
  var res = xs ? (
      xs[0] === "A" ? /* tuple */[
          true,
          $$Array.of_list(xs[1]).join("")
        ] : /* tuple */[
          false,
          str
        ]
    ) : /* tuple */[
      false,
      ""
    ];
  console.log("RES:", res);
  return res;
}

exports.list_to_string = list_to_string;
exports.string_to_list = string_to_list;
exports.aParser = aParser;
/* No side effect */
