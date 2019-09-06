open Utils;

/*  */
type values('a) = list('a);

/*  */
type remaining = string;

/*  */
type result('a) =
  | Success(list('a), remaining)
  | Fail(string);

/*  */
type parser('a) = string => result('a);

/* Parsers a single character */
let pChar = (charToMatch: string): parser('a) =>
  str => {
    let xs = list_of_string(str);

    switch (xs) {
    | [] => Fail("No more input")
    | [head, ...tail] when charToMatch == head => Success([head], string_of_list(tail))
    | _ =>
      let first = List.hd(xs);
      Fail({j|Expecting $charToMatch, got $first|j});
    };
  };

/* Makes our parser a functor */
let mapP = (fn: 'a => 'b, parser: parser('a)): parser('b) =>
  input =>
    switch (parser(input)) {
    | Success(values, remaining) =>
      let newVal = fn(values);
      Success(newVal, remaining);
    | Fail(err) => Fail(err)
    };

/* MapP infix operator */
let (<!>) = mapP;

/* Flipped arguments of MapP */
/* I don't know why we need the version above (<!>) */
let (|>>) = (x, f) => mapP(f, x);