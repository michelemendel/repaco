open Jest;
open Parsers;
open ParsersExtended;
open Combinators;
open Utils;
/* open TC.ParserF */

describe("Success with mapP and three parseDigit", () => {
  let input = "123A";
  let expected = Success("123", "A");
  let parseThreeDigitsAsString = parseDigit ->>- parseDigit ->>- parseDigit |>> string_of_list;
  let actual = run(parseThreeDigitsAsString, input);

  let p1 = parseDigit;
  let p2 = mapP(x => x, p1);
  let r1 = run(p2, "123");
  /* let r2 = fmap(x => x, p1); */
  /*
   ('a => 'b, parser('a), string) => result('b)
   ('a => 'b, parser('a)) => parser('b)
   ('a => 'b, ParserF.t('a)) => ParserF.t('b)
   */

  Js.log2("---r1", r1);

  Expect.(test("succeed with " ++ input, () =>
            expect(actual) |> toEqual(expected)
          ));
});

describe("Success with mapP to an int", () => {
  let input = "123A";
  let expected = Success(123, "A");
  let parseThreeDigitsAsString = parseDigit ->>- parseDigit ->>- parseDigit |>> string_of_list;
  let parseThreeDigitsAsInt = parseThreeDigitsAsString |>> int_of_string;
  let actual = run(parseThreeDigitsAsInt, input);

  Expect.(test("succeed with " ++ input, () =>
            expect(actual) |> toEqual(expected)
          ));
});