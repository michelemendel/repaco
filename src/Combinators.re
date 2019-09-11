open Parsers;

/*  */
let andThen = (parser1, parser2) => {
  let pfn = input =>
    switch (run(parser1, input)) {
    | Fail(err) => Fail(err)
    | Success(value1, remaining1) =>
      switch (run(parser2, remaining1)) {
      | Fail(err) => Fail(err)
      | Success(value2, remaining2) => Success(value1 @ value2, remaining2)
      }
    };

  Parser(pfn);
};

/* AndThen infix operator */
let (->>-) = andThen;

/*  */
let orElse = (parser1, parser2) => {
  let pfn = input =>
    switch (run(parser1, input)) {
    | Success(value1, remaining) => Success(value1, remaining)
    | Fail(_) =>
      switch (run(parser2, input)) {
      | Success(value2, remaining) => Success(value2, remaining)
      | Fail(err) => Fail(err)
      }
    };

  Parser(pfn);
};

/* OrElse infix operator */
let (<|>) = orElse;