open Parsers;
open Combinators;

let anyOf = listOfCharacters => listOfCharacters |> List.map(pChar) |> choice;

let parseUppercase = anyOf(Constants.uppercaseChars);
let parseLowercase = anyOf(Constants.lowercaseChars);
let parseDigit = anyOf(Constants.digits);