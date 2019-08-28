open Jest;
open Parser;

describe("Parse ABC with char to match A", () => {
  let input = "ABC";
  let actual = pchar("A", input);
  let expected = (true, "BC");

  Expect.(
    test("succeed with " ++ input, () =>
      expect(actual) |> toEqual(expected)
    )
  );

  let input = "XBC";
  let actual = pchar("A", input);
  let expected = (false, "Expecting A, got X");

  Expect.(
    test("fail with no matchable string", () =>
      expect(actual) |> toEqual(expected)
    )
  );

  let input = "";
  let actual = pchar("", input);
  let expected = (false, "No more input");

  Expect.(
    test("fail with empty string", () =>
      expect(actual) |> toEqual(expected)
    )
  );
});