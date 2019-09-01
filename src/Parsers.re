open Utils;

type result('a) =
  | Success('a)
  | Fail(string);

type parser('a) = string => result('a);

let pChar = (charToMatch: string): parser('a) =>
  str => {
    let xs = string_to_list(str);

    switch (xs) {
    | [] => Fail("No more input")
    | [head, ...tail] when charToMatch == head =>
      Success((head, list_to_string(tail)))
    | _ =>
      let first = List.hd(xs);
      Fail({j|Expecting $charToMatch, got $first|j});
    };
  };