open Utils;

/*  */
type values('a) = list('a);

/*  */
type remaining = string;
type message = string;

let genericErrorMessage = (msg: string) => "Something went wrong:" ++ msg;

/*  */
type result('a) =
  | Success('a, remaining)
  | Fail(message);

/*  */
type parser('a) = string => result('a);

/* Parses a single character */
let pChar = (charToMatch: string): parser('a) =>
  input => {
    let xs = list_of_string(input);

    switch (xs) {
    | [] => Fail("No more input")
    | [head, ...tail] when charToMatch == head =>
      Success([head], string_of_list(tail))
    | _ =>
      let first = List.hd(xs);
      Fail({j|Expecting $charToMatch, got $first|j});
    };
  };

/* Makes our parser a functor */
/* type mapPType('a, 'b, 'c) = ('a => 'b, parser('a, 'c)) => parser('b, 'c); */
let mapP = (fn: 'a => 'b, parser: parser('a), input): result('b) =>
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