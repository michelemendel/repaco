let string_of_list = (xs: list(string)): string =>
  Js.Array.joinWith("", Array.of_list(xs));

let list_of_string = (str: string): list(string) =>
  Array.to_list(Js.String.split("", str));

let int_of_string_of_list = xs => xs->string_of_list->int_of_string;