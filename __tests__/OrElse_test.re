open Jest;
open Parsers;
open Combinators;

describe("Success with orElse of two parsers, success on first", () => {
  let input = "ABCDEF";
  let charToMatchA = "A";
  let charToMatchB = "B";
  let remaining = "BCDEF";

  let parseA = pChar(charToMatchA);
  let parseB = pChar(charToMatchB);
  let parseAElseB = parseA <|> parseB;

  let actual = parseAElseB(input);
  let expected = Success(("A", remaining));

  Expect.(
    test("succeed with " ++ input, () =>
      expect(actual) |> toEqual(expected)
    )
  );
});

describe("Success with orElse of two parsers, success on second", () => {
  let input = "BCDEF";
  let charToMatchA = "A";
  let charToMatchB = "B";
  let remaining = "CDEF";

  let parseA = pChar(charToMatchA);
  let parseB = pChar(charToMatchB);
  let parseAElseB = parseA <|> parseB;

  let actual = parseAElseB(input);
  let expected = Success(("B", remaining));

  Expect.(
    test("succeed with " ++ input, () =>
      expect(actual) |> toEqual(expected)
    )
  );
});

describe("Success with andThen and orElse of three parsers", () => {
  let input = "ABCDEF";
  let charToMatchA = "A";
  let charToMatchB = "B";
  let charToMatchC = "C";
  let remaining = "CDEF";

  let parseA = pChar(charToMatchA);
  let parseB = pChar(charToMatchB);
  let parseC = pChar(charToMatchC);
  let parseBOrC = parseB <|> parseC;
  let parseAThenBOrC = parseA ->>- parseBOrC;

  let actual = parseAThenBOrC(input);
  let expected = Success((("A", "B"), remaining));

  Expect.(
    test("succeed with " ++ input, () =>
      expect(actual) |> toEqual(expected)
    )
  );
});

describe("Failure with andThen and success with orElse of three parsers", () => {
  let input = "ACDEF";
  let charToMatchA = "A";
  let charToMatchB = "B";
  let charToMatchC = "C";
  let remaining = "DEF";

  let parseA = pChar(charToMatchA);
  let parseB = pChar(charToMatchB);
  let parseC = pChar(charToMatchC);
  let parseBOrC = parseB <|> parseC;
  let parseAThenBOrC = parseA ->>- parseBOrC;

  let actual = parseAThenBOrC(input);
  let expected = Success((("A", "C"), remaining));

  Expect.(
    test("succeed with " ++ input, () =>
      expect(actual) |> toEqual(expected)
    )
  );
});

describe(
  "Failure with andThen and with orElse of three parsers. Fail on first.", () => {
  let input = "XBCDEF";
  let charToMatchA = "A";
  let charToMatchB = "B";
  let charToMatchC = "C";

  let parseA = pChar(charToMatchA);
  let parseB = pChar(charToMatchB);
  let parseC = pChar(charToMatchC);
  let parseBOrC = parseB <|> parseC;
  let parseAThenBOrC = parseA ->>- parseBOrC;

  let actual = parseAThenBOrC(input);
  let expected = Fail({j|Expecting A, got X|j});

  Expect.(
    test("succeed with " ++ input, () =>
      expect(actual) |> toEqual(expected)
    )
  );
});

describe(
  "Failure with andThen and with orElse of three parsers. Fail on second.", () => {
  let input = "AXCDEF";
  let charToMatchA = "A";
  let charToMatchB = "B";
  let charToMatchC = "C";

  let parseA = pChar(charToMatchA);
  let parseB = pChar(charToMatchB);
  let parseC = pChar(charToMatchC);
  let parseBOrC = parseB <|> parseC;
  let parseAThenBOrC = parseA ->>- parseBOrC;

  let actual = parseAThenBOrC(input);
  let expected = Fail("Expecting C, got X"); /* Should say "Expecting B, got X" */

  Expect.(
    test("succeed with " ++ input, () =>
      expect(actual) |> toEqual(expected)
    )
  );
});