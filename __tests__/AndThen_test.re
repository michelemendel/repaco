open Jest;
open Parser;

describe("Success with sequence of two parsers", () => {
  let input = "ABCDEF";
  let charToMatchA = "A";
  let charToMatchB = "B";
  let remaining = "CDEF";

  let parseA = pchar(charToMatchA);
  let parseB = pchar(charToMatchB);
  let parseAThenB = parseA ->>- parseB;

  let actual = parseAThenB(input);
  let expected = Success(("A", "B", remaining));

  Expect.(test("succeed with " ++ input, () =>
            expect(actual) |> toEqual(expected)
          ));
});

describe("Failure with sequence of two parsers on first character", () => {
  let input = "ZBCDEF";
  let firstChar = Js.String.charAt(0, input);
  let charToMatchA = "A";
  let charToMatchB = "B";

  let parseA = pchar(charToMatchA);
  let parseB = pchar(charToMatchB);
  let parseAThenB = parseA ->>- parseB;

  let actual = parseAThenB(input);
  let expected = Parser.Failure({j|Expecting $charToMatchA, got $firstChar|j});

  Expect.(test("fail with " ++ input, () =>
            expect(actual) |> toEqual(expected)
          ));
});

describe("Failure with sequence of two parsers on second character", () => {
  let input = "AZCDEF";
  let secondChar = Js.String.charAt(1, input);
  let charToMatchA = "A";
  let charToMatchB = "B";

  let parseA = pchar(charToMatchA);
  let parseB = pchar(charToMatchB);
  let parseAThenB = parseA ->>- parseB;

  let actual = parseAThenB(input);
  let expected = Parser.Failure({j|Expecting $charToMatchB, got $secondChar|j});

  Expect.(test("fail with " ++ input, () =>
            expect(actual) |> toEqual(expected)
          ));
});