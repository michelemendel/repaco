// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE
'use strict';

var Jest = require("@glennsl/bs-jest/src/jest.js");
var Block = require("bs-platform/lib/js/block.js");
var Parsers$Repaco = require("../src/Parsers.bs.js");
var Combinators$Repaco = require("../src/Combinators.bs.js");

Jest.describe("Success with orElse of two parsers, success on first", (function (param) {
        var input = "ABCDEF";
        var parseA = function (param) {
          return Parsers$Repaco.pChar("A", param);
        };
        var parseB = function (param) {
          return Parsers$Repaco.pChar("B", param);
        };
        var actual = Combinators$Repaco.$less$pipe$great(parseA, parseB, input);
        var expected = /* Success */Block.__(0, [/* tuple */[
              "A",
              "BCDEF"
            ]]);
        return Jest.test("succeed with ABCDEF", (function (param) {
                      return Jest.Expect[/* toEqual */12](expected, Jest.Expect[/* expect */0](actual));
                    }));
      }));

Jest.describe("Success with orElse of two parsers, success on second", (function (param) {
        var input = "BCDEF";
        var parseA = function (param) {
          return Parsers$Repaco.pChar("A", param);
        };
        var parseB = function (param) {
          return Parsers$Repaco.pChar("B", param);
        };
        var actual = Combinators$Repaco.$less$pipe$great(parseA, parseB, input);
        var expected = /* Success */Block.__(0, [/* tuple */[
              "B",
              "CDEF"
            ]]);
        return Jest.test("succeed with BCDEF", (function (param) {
                      return Jest.Expect[/* toEqual */12](expected, Jest.Expect[/* expect */0](actual));
                    }));
      }));

Jest.describe("Success with andThen and orElse of three parsers", (function (param) {
        var input = "ABCDEF";
        var parseA = function (param) {
          return Parsers$Repaco.pChar("A", param);
        };
        var parseB = function (param) {
          return Parsers$Repaco.pChar("B", param);
        };
        var parseC = function (param) {
          return Parsers$Repaco.pChar("C", param);
        };
        var parseBOrC = function (param) {
          return Combinators$Repaco.$less$pipe$great(parseB, parseC, param);
        };
        var actual = Combinators$Repaco.$neg$great$great$neg(parseA, parseBOrC, input);
        var expected = /* Success */Block.__(0, [/* tuple */[
              /* tuple */[
                "A",
                "B"
              ],
              "CDEF"
            ]]);
        return Jest.test("succeed with ABCDEF", (function (param) {
                      return Jest.Expect[/* toEqual */12](expected, Jest.Expect[/* expect */0](actual));
                    }));
      }));

Jest.describe("Failure with andThen and success with orElse of three parsers", (function (param) {
        var input = "ACDEF";
        var parseA = function (param) {
          return Parsers$Repaco.pChar("A", param);
        };
        var parseB = function (param) {
          return Parsers$Repaco.pChar("B", param);
        };
        var parseC = function (param) {
          return Parsers$Repaco.pChar("C", param);
        };
        var parseBOrC = function (param) {
          return Combinators$Repaco.$less$pipe$great(parseB, parseC, param);
        };
        var actual = Combinators$Repaco.$neg$great$great$neg(parseA, parseBOrC, input);
        var expected = /* Success */Block.__(0, [/* tuple */[
              /* tuple */[
                "A",
                "C"
              ],
              "DEF"
            ]]);
        return Jest.test("succeed with ACDEF", (function (param) {
                      return Jest.Expect[/* toEqual */12](expected, Jest.Expect[/* expect */0](actual));
                    }));
      }));

Jest.describe("Failure with andThen and with orElse of three parsers. Fail on first.", (function (param) {
        var input = "XBCDEF";
        var parseA = function (param) {
          return Parsers$Repaco.pChar("A", param);
        };
        var parseB = function (param) {
          return Parsers$Repaco.pChar("B", param);
        };
        var parseC = function (param) {
          return Parsers$Repaco.pChar("C", param);
        };
        var parseBOrC = function (param) {
          return Combinators$Repaco.$less$pipe$great(parseB, parseC, param);
        };
        var actual = Combinators$Repaco.$neg$great$great$neg(parseA, parseBOrC, input);
        return Jest.test("succeed with XBCDEF", (function (param) {
                      return Jest.Expect[/* toEqual */12](/* Fail */Block.__(1, ["Expecting A, got X"]), Jest.Expect[/* expect */0](actual));
                    }));
      }));

Jest.describe("Failure with andThen and with orElse of three parsers. Fail on second.", (function (param) {
        var input = "AXCDEF";
        var parseA = function (param) {
          return Parsers$Repaco.pChar("A", param);
        };
        var parseB = function (param) {
          return Parsers$Repaco.pChar("B", param);
        };
        var parseC = function (param) {
          return Parsers$Repaco.pChar("C", param);
        };
        var parseBOrC = function (param) {
          return Combinators$Repaco.$less$pipe$great(parseB, parseC, param);
        };
        var actual = Combinators$Repaco.$neg$great$great$neg(parseA, parseBOrC, input);
        return Jest.test("succeed with AXCDEF", (function (param) {
                      return Jest.Expect[/* toEqual */12](/* Fail */Block.__(1, ["Expecting C, got X"]), Jest.Expect[/* expect */0](actual));
                    }));
      }));

/*  Not a pure module */
