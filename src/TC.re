/* open Parsers; */

/****************************************
 * Type classes
 *
 * NOTE! This module and its test file are part of the
 * application. I am just playing with module signatures
 * and type classes from the site
 * http://blog.shaynefletcher.org/2017/05/more-type-classes-in-ocaml.html?m=1.
 * */

let id = x => x;
let (<<) = (f, g, x) => f(g(x));
let (>>) = (f, g, x) => g(f(x));
let (<.>) = (>>);

/*
 Functor
 */

module type Functor = {
  type t('a);
  let fmap: ('a => 'b, t('a)) => t('b);
};

module type Functor2 = {
  type t('a, 'b);
  let fmap: ('a0 => 'b, t('a, 'a0)) => t('a, 'b);
};

module TestFunctor = (F: Functor) => {
  let test_id = x => assert(F.fmap(id, x) == x);
  let test_compose = (f, g, x) =>
    assert(F.fmap(f <.> g, x) == F.fmap(f, F.fmap(g, x)));
};

module TestEitherFunctor = (F: Functor2) => {
  let test_id = x => assert(F.fmap(id, x) == x);
  let test_compose = (f, g, x) =>
    assert(F.fmap(f <.> g, x) == F.fmap(f, F.fmap(g, x)));
};

module ListF: Functor with type t('a) = list('a) = {
  type t('a) = list('a);
  let fmap = f => List.map(f);
};

module OptionF: Functor with type t('a) = option('a) = {
  type t('a) = option('a);
  let fmap = (f, a) =>
    switch (a) {
    | Some(x) => Some(f(x))
    | None => None
    };
};

type either('a, 'b) =
  | Left('a)
  | Right('b);

module EitherF: Functor2 with type t('a, 'b) = either('a, 'b) = {
  type t('a, 'b) = either('a, 'b);
  let fmap = f =>
    fun
    | Left(err) => Left(err)
    | Right(x) => Right(f(x));
};

/* module ParserF: Functor with type t('a) = result('a) = {
     type t('a) = result('a);
     let fmap = (f, result) =>
       switch (result) {
       | Success(vals, rem) => Success(f(vals), rem)
       | Fail(err) => Fail(err)
       };
   };

   let (<$>) = (x, f) => ParserF.fmap(f, x); */

/*
 Monoid
 */

module type Monoid = {
  type t;
  let empty: t;
  let append: (t, t) => t;
};

module MonoidUtils = (M: Monoid) => {
  include M;
  let (<+>) = (x, y) => append(x, y);
  let concat = xs => List.fold_left((<+>), empty, xs);
};

module type TYPE = {type t;};

module ListMonoid = (T: TYPE) : (Monoid with type t = list(T.t)) => {
  type t = list(T.t);
  let empty = [];
  let append = (xs, ys) => xs @ ys;
};

let concat = (type a, xs) => {
  module MU =
    MonoidUtils(
      (
        ListMonoid({
          type t = a;
        })
      ),
    );
  MU.concat(xs);
};

/*
 Applicative
 */

module type Applicative = {
  include Functor;
  let pure: 'a => t('a);
  let apply: (t('a => 'b), t('a)) => t('b);
};

module ListApplicative: Applicative with type t('a) = list('a) = {
  include ListF;
  let pure = x => [x];
  let apply = (fs, xs) =>
    concat @@ List.map(f => List.map(x => f(x), xs), fs);
};