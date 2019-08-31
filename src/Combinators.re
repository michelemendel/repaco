open Parsers;

let andThen = (parser1: parser('a), parser2: parser('b), input): result('c) =>
  switch (parser1(input)) {
  | Fail(err) => Fail(err)
  | Success((result1, remaining1)) =>
    switch (parser2(remaining1)) {
    | Fail(err) => Fail(err)
    | Success((result2, remaining2)) =>
      Success(((result1, result2), remaining2))
    }
  };

/* AndThen infix operator */
let (->>-) = andThen;

let orElse = (parser1, parser2, input) =>
  switch (parser1(input)) {
  | Success((result1, remaining)) => Success((result1, remaining))
  | Fail(_) =>
    switch (parser2(input)) {
    | Success((result2, remaining)) => Success((result2, remaining))
    | Fail(err) => Fail(err)
    }
  };

/* OrElse infix operator */
let (<|>) = orElse;