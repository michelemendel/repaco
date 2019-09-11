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
type parser('a) =
  | Parser(string => result('a));

let run = (parser, input) => {
  let Parser(innerFn) = parser;
  innerFn(input);
};

/* Parses a single character */
let pChar = charToMatch => {
  let pfn = input => {
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

  Parser(pfn);
};

/* Makes our parser a functor */
let mapP = (fn: 'a => 'b, parser: parser('a)): parser('b) => {
  let pfn = input =>
    switch (run(parser, input)) {
    | Success(values, remaining) =>
      let newVal = fn(values);
      Success(newVal, remaining);
    | Fail(err) => Fail(err)
    };

  Parser(pfn);
};

/* Flipped arguments of MapP */
/* I don't know why we need the version above (<!>) */
let (|>>) = (x, f) => mapP(f, x);