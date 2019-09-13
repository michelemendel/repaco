open Jest;
open TC;
/*
 open Parsers;
 open ParsersExtended;
 open Combinators;
 open Utils;
 */

describe("ListF - Validating functor rules", () => {
  open Expect;
  module FTest = TestFunctor(ListF);

  let f = x => x;
  let g = x => 2 * x;

  let expected = [(), ()];

  let actualId = FTest.test_id([1]);
  let actualCompose = FTest.test_compose(f, g, [1]);
  let actuals = [actualId, actualCompose];

  test("succeess ", () =>
    expect(expected) |> toEqual(actuals)
  );
});

describe("ListF - Validating functor rules", () => {
  open Expect;
  module FTest = TestFunctor(ListF);

  let f = x => x;
  let g = x => 2 * x;

  let expected = [(), ()];

  let actualId = FTest.test_id([1]);
  let actualCompose = FTest.test_compose(f, g, [1]);
  let actuals = [actualId, actualCompose];

  test("succeess ", () =>
    expect(expected) |> toEqual(actuals)
  );
});

describe("EitherF - Validating functor rules", () => {
  open Expect;
  module FTest = TestEitherFunctor(EitherF);

  let f = x => x;
  let g = x => 2 * x;

  let expected = [(), ()];

  let actualId = FTest.test_id(Right());
  let actualCompose = FTest.test_compose(f, g, Right(1));
  let actuals = [actualId, actualCompose];

  test("succeess ", () =>
    expect(expected) |> toEqual(actuals)
  );
});

/* describe("ParserF - Validating functor rules", () => {
     module ParserFTest = TestFunctor(ParserF);
     let res = pChar("a", "abc");
     let f = x => x;
     let g = x => x;

     let actualId = ParserFTest.test_id(res);
     let actualCompose = ParserFTest.test_compose(f, g, res);
     let actuals = [actualId, actualCompose];

     Expect.(test("succeed with ", () =>
               toEqual([(), ()], expect(actuals))
             ));
   }); */