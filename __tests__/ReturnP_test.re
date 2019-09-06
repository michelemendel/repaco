open Jest;
open Parsers;
open ParsersExtended;

describe("Success with returnP", () => {
  let x = "A";
  let remaining = "rem";

  let expected = Success([x], remaining);
  let actualP = returnP(x);
  let actual = actualP(remaining);

  Expect.(test("succeed with ", () =>
            expect(actual) |> toEqual(expected)
          ));
});