let list_to_string = xs => Js.Array.joinWith("", Array.of_list(xs));
let string_to_list = str => Array.to_list(Js.String.split("", str));

let aParser = (str: string): (bool, string) => {
  let xs = string_to_list(str);

  Js.log(xs);
  /* print_endline(Js.Array.joinWith("", xs)); */

  let res =
    switch (xs) {
    | [] => (false, "")
    | ["A", ...tail] => (true, list_to_string(tail))
    | _ => (false, str)
    };

  Js.log2("RES:", res);

  res;
};