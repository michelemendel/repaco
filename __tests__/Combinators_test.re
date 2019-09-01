open Jest;
open Parsers;
open Combinators;

/* type combTest = {
     input: string,
     actual: result('a),
     expected: result(((string, string), string)),
   };

   type combTests =
     | List(combTest);

   let parseA = pChar("A");
   let parseB = pChar("B");
   let parseC = pChar("C");

   let succA: combTest = {
     input: "ABCDEF",
     actual: (parseA ->>- parseB)("ABCDEF"),
     expected: Success((("A", "B"), "CDEF")),
   };

   let succB: combTest = {
     input: "ABCDEF",
     actual: (parseA ->>- parseB ->>- parseC)("ABCDEF"),
     expected: Success((("A", "B", "C"), "DEF")),
   };
    */
describe("Testing combinators", () => {
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