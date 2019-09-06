open Jest;
open Parsers;
open ParsersExtended;
open Combinators;
open Utils;

describe("Success with mapP and three parseDigit", () => {
  let input = "123A";
  let expected = Success("123", "A");
  let parseThreeDigitsAsString = parseDigit ->>- parseDigit ->>- parseDigit |>> string_of_list;
  let actual = parseThreeDigitsAsString(input);

  Expect.(test("succeed with " ++ input, () =>
            expect(actual) |> toEqual(expected)
          ));
});

describe("Success with mapP to an int", () => {
  let input = "123A";
  let expected = Success(123, "A");
  let parseThreeDigitsAsString = parseDigit ->>- parseDigit ->>- parseDigit |>> string_of_list;
  let parseThreeDigitsAsInt = parseThreeDigitsAsString |>> int_of_string;
  let actual = parseThreeDigitsAsInt(input);

  Expect.(test("succeed with " ++ input, () =>
            expect(actual) |> toEqual(expected)
          ));
});