open Jest;
open TC;
open Parsers;

module ListFTest = TestFunctor(ListF);
module ParserFTest = TestFunctor(ParserF);

describe("ListF - Testing functor rules", () => {
  let f = x => x;
  let g = x => 2 * x;

  let actualId = ListFTest.test_id([1]);
  let actualCompose = ListFTest.test_compose(f, g, [1]);
  let actuals = [actualId, actualCompose];

  Expect.(test("succeed with ", () =>
            toEqual([(), ()], expect(actuals))
          ));
});

describe("ParserF - Testing functor rules", () => {
  let res = pChar("a", "abc");
  let f = x => x;
  let g = x => x;

  let actualId = ParserFTest.test_id(res);
  let actualCompose = ParserFTest.test_compose(f, g, res);
  let actuals = [actualId, actualCompose];

  Expect.(test("succeed with ", () =>
            toEqual([(), ()], expect(actuals))
          ));
});