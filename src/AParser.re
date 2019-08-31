open Utils;

let aParser = (str: string): (bool, string) => {
  let xs = string_to_list(str);

  /* Js.log(xs); */
  /* print_endline(Js.Array.joinWith("", xs)); */

  switch (xs) {
  | [] => (false, "")
  | ["A", ...tail] => (true, list_to_string(tail))
  | _ => (false, str)
  };
};