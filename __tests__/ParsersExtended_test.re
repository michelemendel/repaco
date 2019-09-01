open Jest;
open Parsers;
open ParsersExtended;
open Combinators;

let upperOrLowerOrDigit =
  choice([parseLowercase, parseUppercase, parseDigit]);

describe("Success with upperOrLowerOrDigit", () => {
  let input = "9BCDEF";
  let actual = upperOrLowerOrDigit(input);
  let expected = Success(["9"], "BCDEF");

  Expect.(
    test("succeed with " ++ input, () =>
      expect(actual) |> toEqual(expected)
    )
  );
});

describe("Fail with upperOrLowerOrDigit", () => {
  let input = "_BCDEF";
  let actual = upperOrLowerOrDigit(input);
  let expected = Fail("Expecting 9, got _");

  Expect.(
    test("fail with " ++ input, () =>
      expect(actual) |> toEqual(expected)
    )
  );
});