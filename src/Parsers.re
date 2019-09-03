open Utils;

type values('a) = list('a);
type remaining = string;

type result('a) =
  | Success(values('a), remaining)
  | Fail(string);

type parser('a) = string => result('a);

let pChar = (charToMatch: string): parser('a) =>
  str => {
    let xs = string_to_list(str);

    switch (xs) {
    | [] => Fail("No more input")
    | [head, ...tail] when charToMatch == head =>
      Success([head], list_to_string(tail))
    | _ =>
      let first = List.hd(xs);
      Fail({j|Expecting $charToMatch, got $first|j});
    };
  };

let mapP = (fn: values('a) => 'b, parser: parser('a)): parser('b) =>
  input =>
    switch (parser(input)) {
    | Success(values, remaining) =>
      let newVal = fn(values);
      Success([newVal], remaining);
    | Fail(err) => Fail(err)
    /* | _ => Fail("Something went wrong") */
    };

/* MapP infix operator */
let (<!>) = mapP;

/* Flippen arguments of MapP */
/* I don't know why we need the version above (<!>) */
let (|>>) = (x, f) => mapP(f, x);