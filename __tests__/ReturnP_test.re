open Jest;
open Parsers;

describe("Success with returnP", () => {
  let x = "A";
  let remaining = "rem";

  let expected = Success([x], remaining);
  let actual = returnP(x, remaining);

  Expect.(test("succeed with ", () =>
            expect(actual) |> toEqual(expected)
          ));
});