open Parsers;
open Combinators;
/* open Utils; */

/* Choice */
let choice = listOfParsers =>
  List.fold_left(orElse, pChar(""), listOfParsers);

let anyOf = listOfCharacters => listOfCharacters |> List.map(pChar) |> choice;

let parseUppercase = anyOf(Constants.uppercaseChars);

let parseLowercase = anyOf(Constants.lowercaseChars);

let parseDigit = anyOf(Constants.digits);

/*
 Lift functions
 */

/* Ignore the input and return x */
/* The comment above is from the blog, and I don't understand how "input is ignored." */
type returnPType('a) = ('a, remaining) => result('a);
let returnP: returnPType('a) = (x, input) => Success(x, input);

/* Makes our parser an applicative */
type applyPType('a, 'b) = (parser('a), parser('b)) => parser('b);
let applyP = (fP, xP) => {
  /* let x1 = fP ->>- xP; */
  /* type parser('a) = string => result('a) */
  /* let x1b = returnP(fP); */
  /* let fn = (f, x:string) => f(x); */
  /* let y3 = mapP(fn, pChar("")); */
  /* let fn2 = (f, g) => ""; */
  /* let y3b = mapP(fn2, x1); */
  /* fP ->>- xP |> mapP(fn); */

  /*   switch (fP) {
        | Success(vals, rem) =>
          Js.log2("----", vals);
          returnP(vals);
        | Fail(err) => returnP("err")
        };
       */
  let _ = 4;
  ();
  /*   returnP(["A"]); */
};