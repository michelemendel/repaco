open Jest;
open Parsers;
open Combinators;

let parseA = pChar("A");
let parseB = pChar("B");
let parseC = pChar("C");

describe("Success with andThen of two parsers", () => {
  let input = "ABCDEF";
  let actual = run(parseA ->>- parseB, input);
  let expected = Success(["A", "B"], "CDEF");

  Expect.(
    test("succeed with " ++ input, () =>
      expect(actual) |> toEqual(expected)
    )
  );
});

describe("Success with andThen of three parsers", () => {
  let input = "ABCDEF";
  let actual = run(parseA ->>- parseB ->>- parseC, input);
  let expected = Success(["A", "B", "C"], "DEF");

  Expect.(
    test("succeed with " ++ input, () =>
      expect(actual) |> toEqual(expected)
    )
  );
});

describe("Fail with sequence of two parsers on first character", () => {
  let input = "ZBCDEF";
  let actual = run(parseA ->>- parseB, input);
  let expected = Fail("Expecting A, got Z");

  Expect.(
    test("fail with " ++ input, () =>
      expect(actual) |> toEqual(expected)
    )
  );
});

describe("Fail with sequence of two parsers on second character", () => {
  let input = "AZCDEF";
  let actual = run(parseA ->>- parseB, input);
  let expected = Fail("Expecting B, got Z");

  Expect.(
    test("fail with " ++ input, () =>
      expect(actual) |> toEqual(expected)
    )
  );
});