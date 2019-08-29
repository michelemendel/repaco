open Utils;

type result('a) =
  | Success(string, 'a)
  | Failure(string);

/* type t = Parser; */

let pchar = (charToMatch: string) => {   
    let inner = (str:string): result('a) => {
        let xs = string_to_list(str);
        switch (xs) {
        | [] => Failure("No more input")
        | [head, ...tail] when charToMatch == head =>
        Success(head, list_to_string(tail))
        | _ => let first = List.hd(xs);
        Failure({j|Expecting $charToMatch, got $first|j});
        }
    };
inner;
}
