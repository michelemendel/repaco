open Parsers;

let andThen = (parser1: parser('a), parser2: parser('b)): parser('c) =>
  input =>
    switch (parser1(input)) {
    | Fail(err) => Fail(err)
    | Success(value1, remaining1) =>
      switch (parser2(remaining1)) {
      | Fail(err) => Fail(err)
      | Success(value2, remaining2) =>
        Success(List.append(value1, value2), remaining2)
      }
    };

/* AndThen infix operator */
let (->>-) = andThen;

let orElse = (parser1: parser('a), parser2: parser('b)): parser('c) =>
  input =>
    switch (parser1(input)) {
    | Success([value1], remaining) => Success([value1], remaining)
    | Fail(_) =>
      switch (parser2(input)) {
      | Success([value2], remaining) => Success([value2], remaining)
      | Fail(err) => Fail(err)
      | _ => Fail("Something went wrong")
      }
    | _ => Fail("Something went wrong")
    };

/* OrElse infix operator */
let (<|>) = orElse;