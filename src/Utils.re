let string_of_list = xs => Js.Array.joinWith("", Array.of_list(xs));
let list_of_string = str => Array.to_list(Js.String.split("", str));

let int_of_string_of_list = s => s->string_of_list->int_of_string;