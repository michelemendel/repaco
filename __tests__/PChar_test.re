open Jest;
open Parsers;

describe("Parse ABC with char to match A", () => {
  let input = "ABC";
  let parseA = pChar("A");
  let actual = parseA(input);
  let expected = Success(["A"], "BC");

  Expect.(
    test("succeed with " ++ input, () =>
      expect(actual) |> toEqual(expected)
    )
  );
});

describe("Parse XBC with char to match A", () => {
  let input = "XBC";
  let parseA = pChar("A");
  let actual = parseA(input);
  let expected = Fail("Expecting A, got X");

  Expect.(
    test("fail with no matchable string", () =>
      expect(actual) |> toEqual(expected)
    )
  );
});

describe("Parse empty string with char to match A", () => {
  let input = "";
  let parseA = pChar("A");
  let actual = parseA(input);
  let expected = Fail("No more input");

  Expect.(
    test("fail with empty string", () =>
      expect(actual) |> toEqual(expected)
    )
  );
});