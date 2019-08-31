open Jest;
open Parsers;
open Combinators;

describe("Success with andThen of two parsers", () => {
  let input = "ABCDEF";
  let charToMatchA = "A";
  let charToMatchB = "B";
  let remaining = "CDEF";

  let parseA = pChar(charToMatchA);
  let parseB = pChar(charToMatchB);
  let parseAThenB = parseA ->>- parseB;

  let actual = parseAThenB(input);
  let expected = Success((("A", "B"), remaining));

  Expect.(
    test("succeed with " ++ input, () =>
      expect(actual) |> toEqual(expected)
    )
  );
});

describe("Success with andThen of three parsers", () => {
  let input = "ABCDEF";
  let charToMatchA = "A";
  let charToMatchB = "B";
  let charToMatchC = "C";
  let remaining = "DEF";

  let parseA = pChar(charToMatchA);
  let parseB = pChar(charToMatchB);
  let parseC = pChar(charToMatchC);
  let parseAThenBThenC = parseA ->>- parseB ->>- parseC;

  let actual = parseAThenBThenC(input);
  let expected = Success(((("A", "B"), "C"), remaining));

  Expect.(
    test("succeed with " ++ input, () =>
      expect(actual) |> toEqual(expected)
    )
  );
});

describe("Fail with sequence of two parsers on first character", () => {
  let input = "ZBCDEF";
  let firstChar = Js.String.charAt(0, input);
  let charToMatchA = "A";
  let charToMatchB = "B";

  let parseA = pChar(charToMatchA);
  let parseB = pChar(charToMatchB);
  let parseAThenB = parseA ->>- parseB;

  let actual = parseAThenB(input);
  let expected = Fail({j|Expecting $charToMatchA, got $firstChar|j});

  Expect.(
    test("fail with " ++ input, () =>
      expect(actual) |> toEqual(expected)
    )
  );
});

describe("Fail with sequence of two parsers on second character", () => {
  let input = "AZCDEF";
  let secondChar = Js.String.charAt(1, input);
  let charToMatchA = "A";
  let charToMatchB = "B";

  let parseA = pChar(charToMatchA);
  let parseB = pChar(charToMatchB);
  let parseAThenB = parseA ->>- parseB;

  let actual = parseAThenB(input);
  let expected = Fail({j|Expecting $charToMatchB, got $secondChar|j});

  Expect.(
    test("fail with " ++ input, () =>
      expect(actual) |> toEqual(expected)
    )
  );
});