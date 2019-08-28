open Utils;

type result('a) =
  | Success('a)
  | Failure(string);

let pchar = (charToMatch, str: string): (bool, string) => {
  let xs = string_to_list(str);

  Js.log(xs);
  /* print_endline(Js.Array.joinWith("", xs)); */

  let res =
    switch (xs) {
    | [] => (false, "No more input")
    | [head, ...tail] when charToMatch == head => (
        true,
        list_to_string(tail),
      )
    | _ =>
      let first = List.hd(xs);
      (false, {j|Expecting $charToMatch, got $first|j});
    };

  Js.log2("RES:", res);

  res;
};