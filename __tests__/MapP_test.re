open Jest;
open Parsers;
open ParsersExtended;
open Combinators;
open Utils;

describe("Success with mapP and three parseDigit", () => {
  let input = "123A";
  let expected = Success(["123"], "A");

  let parseThreeDigitsAsString =
    parseDigit ->>- parseDigit ->>- parseDigit |>> list_to_string;

  let actual = parseThreeDigitsAsString(input);

  Js.log2("-----", actual);

  Expect.(
    test("succeed with " ++ input, () =>
      expect(actual) |> toEqual(expected)
    )
  );
});