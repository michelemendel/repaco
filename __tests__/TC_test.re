open Jest;
open TC;
/* open Parsers;
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

describe("OptionF - Validating functor rules", () => {
  open Expect;
  module FTest = TestFunctor(OptionF);

  let f = x => x;
  let g = x => 2 * x;

  let expected = [(), ()];

  let actualId = FTest.test_id(Some(1));
  let actualCompose = FTest.test_compose(f, g, Some(1));
  let actuals = [actualId, actualCompose];

  test("succeess ", () =>
    expect(expected) |> toEqual(actuals)
  );
});

describe("Testing OptionF", () => {
  open Expect;
  module F = OptionF;
  let f = x => 2 * x;

  let expected = Some(2);
  let actual = F.fmap(f, Some(1));

  test("succeess ", () =>
    expect(expected) |> toEqual(actual)
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
     open Expect;
     module FTest = TestFunctor(ParserF);
     let res = pChar("a");
     let f = x => x;
     let g = x => x;

     let actualId = FTest.test_id(res);
     let actualCompose = FTest.test_compose(f, g, res);
     let actuals = [actualId, actualCompose];

     test("succeed with ", () =>
       toEqual([(), ()], expect(actuals))
     );
   }); */