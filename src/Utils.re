let list_to_string = xs => Js.Array.joinWith("", Array.of_list(xs));
let string_to_list = str => Array.to_list(Js.String.split("", str));