open Jest;
open Parsers;
open ParsersExtended;

describe("Success with returnP", () => {
  let x = "A";
  let remaining = "";

  let expected = Success(x, remaining);
  let parser = returnP(x);
  let actual = parser(remaining);

  Expect.(test("succeed with ", () =>
            expect(actual) |> toEqual(expected)
          ));
});

describe("Another version with success with returnP", () => {
  let parseA = pChar("A");
  let resA = run(parseA, "ABC");
  let parserB = returnP(["A"]);
  let resB = parserB("BC");

  Expect.(test("succeed with ", () =>
            expect(resA) |> toEqual(resB)
          ));
});