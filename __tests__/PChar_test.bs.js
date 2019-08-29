// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE
'use strict';

var Jest = require("@glennsl/bs-jest/src/jest.js");
var Block = require("bs-platform/lib/js/block.js");
var Parser$Repaco = require("../src/Parser.bs.js");

Jest.describe("Parse ABC with char to match A", (function (param) {
        var input = "ABC";
        var charToMatch = "A";
        var actual = Parser$Repaco.pchar(charToMatch, input);
        var expected = /* Success */Block.__(0, [/* tuple */[
              charToMatch,
              "BC"
            ]]);
        return Jest.test("succeed with ABC", (function (param) {
                      return Jest.Expect[/* toEqual */12](expected, Jest.Expect[/* expect */0](actual));
                    }));
      }));

Jest.describe("Parse XBC with char to match A", (function (param) {
        var charToMatch = "A";
        var actual = Parser$Repaco.pchar(charToMatch, "XBC");
        var expected = /* Failure */Block.__(1, ["Expecting " + (String(charToMatch) + ", got X")]);
        return Jest.test("fail with no matchable string", (function (param) {
                      return Jest.Expect[/* toEqual */12](expected, Jest.Expect[/* expect */0](actual));
                    }));
      }));

Jest.describe("Parse empty string with char to match A", (function (param) {
        var charToMatch = "A";
        var actual = Parser$Repaco.pchar(charToMatch, "");
        return Jest.test("fail with empty string", (function (param) {
                      return Jest.Expect[/* toEqual */12](/* Failure */Block.__(1, ["No more input"]), Jest.Expect[/* expect */0](actual));
                    }));
      }));

/*  Not a pure module */
