open Utils;

type result('a) =
  | Success('a)
  | Failure(string);

type parser('a) =
  (Js.String.t, Js.String.t) => result((Js.String.t, string));

let pchar = (charToMatch: string): parser('a) => {
  let x = str => {
    let xs = string_to_list(str);
    switch (xs) {
    | [] => Failure("No more input")
    | [head, ...tail] when charToMatch == head =>
      Success((head, list_to_string(tail)))
    | _ =>
      let first = List.hd(xs);
      Failure({j|Expecting $charToMatch, got $first|j});
    };
  };
  x;
};

let andThen = (p1: parser('a), p2: parser('a), input) =>
  switch (p1(input)) {
  | Failure(err) => Failure(err)
  | Success((value1, remaining1)) =>
    switch (p2(remaining1)) {
    | Failure(err) => Failure(err)
    | Success((value2, remaining2)) => Success((value1, value2, remaining2))
    }
  };