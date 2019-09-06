open Parsers;
open Combinators;

let anyOf = listOfCharacters => listOfCharacters |> List.map(pChar) |> choice;

let parseUppercase = anyOf(Constants.uppercaseChars);
let parseLowercase = anyOf(Constants.lowercaseChars);
let parseDigit = anyOf(Constants.digits);

/*
 Lift functions
 */

/* Ignore the input and return x */
/* The comment above is from the blog, and I don't understand how "input is ignored." */
let returnP = (x: 'a): parser('b) => input => Success([x], input);

/* let applyP = (fP: parser('a), xP: parser('b)) => {
     let x = fP ->>- xP;
     x;
     // fP  |> mapP((f, x) => f(x));
   }; */