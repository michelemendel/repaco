open Jest;
open Parsers;
open Combinators;

let parseA = pChar("A");
let parseB = pChar("B");
let parseC = pChar("C");

describe(
  "Success with orElse (and choice) of two parsers, success on first", () => {
  let input = "ABCDEF";
  let actual = (parseA <|> parseB)(input);
  let expected = Success(["A"], "BCDEF");

  Expect.(
    test("succeed with " ++ input, () =>
      expect(actual) |> toEqual(expected)
    )
  );

  let actual = choice([parseA, parseB], input);

  Expect.(
    test("succeed (using choice) " ++ input, () =>
      expect(actual) |> toEqual(expected)
    )
  );
});

describe(
  "Success with orElse (and choice) of two parsers, success on second", () => {
  let input = "BCDEF";
  let actual = (parseA <|> parseB)(input);
  let expected = Success(["B"], "CDEF");

  Expect.(
    test("succeed with " ++ input, () =>
      expect(actual) |> toEqual(expected)
    )
  );

  let actual = choice([parseA, parseB], input);

  Expect.(
    test("succeed (using choice) " ++ input, () =>
      expect(actual) |> toEqual(expected)
    )
  );
});

describe("Success with andThen and orElse (and choice) of three parsers", () => {
  let input = "ABCDEF";
  let parseAThenBOrC = parseA ->>- (parseB <|> parseC);
  let actual = parseAThenBOrC(input);
  let expected = Success(["A", "B"], "CDEF");

  Expect.(
    test("succeed with " ++ input, () =>
      expect(actual) |> toEqual(expected)
    )
  );

  let actual = (parseA ->>- choice([parseB, parseC]))(input);

  Expect.(
    test("succeed (using choice) " ++ input, () =>
      expect(actual) |> toEqual(expected)
    )
  );
});

describe(
  "Failure with andThen and success with orElse (and choice) of three parsers",
  () => {
    let input = "ACDEF";
    let parseAThenBOrC = parseA ->>- (parseB <|> parseC);
    let actual = parseAThenBOrC(input);
    let expected = Success(["A", "C"], "DEF");

    Expect.(
      test("succeed with " ++ input, () =>
        expect(actual) |> toEqual(expected)
      )
    );

    let actual = (parseA ->>- choice([parseB, parseC]))(input);

    Expect.(
      test("succeed (using choice) " ++ input, () =>
        expect(actual) |> toEqual(expected)
      )
    );
  },
);

describe(
  "Failure with andThen and with orElse (and choice) of three parsers. Fail on first.",
  () => {
    let input = "XBCDEF";
    let parseAThenBOrC = parseA ->>- (parseB <|> parseC);
    let actual = parseAThenBOrC(input);
    let expected = Fail({j|Expecting A, got X|j});

    Expect.(
      test("fail with " ++ input, () =>
        expect(actual) |> toEqual(expected)
      )
    );

    let actual = (parseA ->>- choice([parseB, parseC]))(input);

    Expect.(
      test("fail (using choice) " ++ input, () =>
        expect(actual) |> toEqual(expected)
      )
    );
  },
);

describe(
  "Failure with andThen and with orElse (and choice) of three parsers. Fail on second.",
  () => {
    let input = "AXCDEF";
    let parseAThenBOrC = parseA ->>- (parseB <|> parseC);
    let actual = parseAThenBOrC(input);
    let expected = Fail("Expecting C, got X"); /* Should say "Expecting B, got X" */

    Expect.(
      test("fail with " ++ input, () =>
        expect(actual) |> toEqual(expected)
      )
    );

    let actual = (parseA ->>- choice([parseB, parseC]))(input);

    Expect.(
      test("fail (using choice) " ++ input, () =>
        expect(actual) |> toEqual(expected)
      )
    );
  },
);