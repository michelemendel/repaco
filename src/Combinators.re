open Parsers;

let andThen = (parser1: parser('a), parser2: parser('b)): parser('c) =>
  input =>
    switch (parser1(input)) {
    | Fail(err) => Fail(err)
    | Success(value1, remaining1) =>
      switch (parser2(remaining1)) {
      | Fail(err) => Fail(err)
      | Success(value2, remaining2) => Success(value1 @ value2, remaining2)
      }
    };

/* AndThen infix operator */
let (->>-) = andThen;

let orElse = (parser1: parser('a), parser2: parser('b)): parser('c) =>
  input =>
    switch (parser1(input)) {
    | Success(value1, remaining) => Success(value1, remaining)
    | Fail(_) =>
      switch (parser2(input)) {
      | Success(value2, remaining) => Success(value2, remaining)
      | Fail(err) => Fail(err)
      }
    };

/* OrElse infix operator */
let (<|>) = orElse;

let choice = listOfParsers =>
  List.fold_left(orElse, pChar(""), listOfParsers);