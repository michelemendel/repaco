open Parsers;

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

module ListF: Functor with type t('a) = list('a) = {
  type t('a) = list('a);
  let fmap = f => List.map(f);
};

module OptionFunctor: Functor with type t('a) = option('a) = {
  type t('a) = option('a);
  let fmap = f =>
    fun
    | Some(x) => Some(f(x))
    | None => None;
};

module ParserF: Functor with type t('a) = result('a) = {
  type t('a) = result('a);
  let fmap = f =>
    fun
    | Success(vals, rem) => Success(f(vals), rem)
    | Fail(err) => Fail(err);
};

module TestFunctor = (F: Functor) => {
  open F;
  let test_id = x => assert(fmap(id, x) == x);
  let test_compose = (f, g, x) =>
    assert(fmap(f <.> g, x) == fmap(f, fmap(g, x)));
};

/*
 Applicative
 */