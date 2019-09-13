open Parsers;

/****************************************
 Type classes
 */

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
  let fmap = f =>
    fun
    | Some(x) => Some(f(x))
    | None => None;
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

module ParserF: Functor with type t('a) = result('a) = {
  type t('a) = result('a);
  let fmap = (f, result) =>
    switch (result) {
    | Success(vals, rem) => Success(f(vals), rem)
    | Fail(err) => Fail(err)
    };
};

let (<$>) = (x, f) => ParserF.fmap(f, x);

/*
 Applicative
 */