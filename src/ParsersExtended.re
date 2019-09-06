open Parsers;
open Combinators;
open Utils;

let anyOf = listOfCharacters => listOfCharacters |> List.map(pChar) |> choice;

let parseUppercase = anyOf(Constants.uppercaseChars);
let parseLowercase = anyOf(Constants.lowercaseChars);
let parseDigit = anyOf(Constants.digits);

/*
 Lift functions
 */

/* Ignore the input and return x */
/* The comment above is from the blog, and I don't understand how "input is ignored." */
type tReturnP('b) = 'b => parser('b);
let returnP: tReturnP('b) = (x, input) => Success(x, input);

type tApplyP('a, 'b) = (parser('a => 'b), parser('a)) => parser('b);
type tApplyP2('a, 'b) = ('a => 'b, parser('a)) => parser('b);
let applyP: tApplyP2('a, 'b) =
  (fP, xP) => {
    let x1 = fP ->>- xP;

    //   let y1 = mapP(string_of_list, fP);

    let y2 = (f, g) => f(g);
    // let y3 = mapP(y2, x1);

    _ => Success("", "");
  };

/*

 This expression - fP - has type
 parser('a => 'b) = string => result('a => 'b)
 but expected
 parser(list('c)) = string => result(list('c))

  */

/*

 x1 is
 parser(list(string)) = string => result(list(string))
 but expected
 parser('a => 'b) = string => result('a => 'b)

 y1 is
 parser('a) = string => result('a

 */