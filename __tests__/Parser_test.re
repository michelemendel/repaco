open Jest;

describe("Parse ABC", () => {
  let input = "ABC";
  let actual = Parser.aParser(input);
  let expected = (true, "BC");

  Expect.(
    test("succeed with " ++ input, () =>
      expect(actual) |> toEqual(expected)
    )
  );

  let input = "XBC";
  let actual = Parser.aParser(input);
  let expected = (false, "XBC");

  Expect.(
    test("fail with no matchable string", () =>
      expect(actual) |> toEqual(expected)
    )
  );

  let input = "";
  let actual = Parser.aParser(input);
  let expected = (false, "");

  Expect.(
    test("fail with empty string", () =>
      expect(actual) |> toEqual(expected)
    )
  );
});