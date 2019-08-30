open Jest;
open Parser;

describe("Parse ABC with char to match A", () => {
  let input = "ABC";
  let charToMatch = "A";
  let remaining = "BC";
  let parseA = pchar(charToMatch);

  let actual = parseA(input);
  let expected = Success((charToMatch, remaining));

  Expect.(
    test("succeed with " ++ input, () =>
      expect(actual) |> toEqual(expected)
    )
  );
});

describe("Parse XBC with char to match A", () => {
  let input = "XBC";
  let charToMatch = "A";
  let parseA = pchar(charToMatch);

  let actual = parseA(input);
  let expected = Parser.Failure({j|Expecting $charToMatch, got X|j});

  Expect.(
    test("fail with no matchable string", () =>
      expect(actual) |> toEqual(expected)
    )
  );
});

describe("Parse empty string with char to match A", () => {
  let input = "";
  let charToMatch = "A";
  let parseA = pchar(charToMatch);

  let actual = parseA(input);
  let expected = Parser.Failure("No more input");

  Expect.(
    test("fail with empty string", () =>
      expect(actual) |> toEqual(expected)
    )
  );
});