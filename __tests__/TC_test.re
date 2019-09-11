open Jest;
open TC;
open Parsers;
/* open ParsersExtended; */
/* open Combinators; */
open Utils;

module ListFTest = TestFunctor(ListF);
module ParserFTest = TestFunctor(ParserF);
module ListF = TC.ListF;
module OptionF = TC.OptionF;
module ParserF = TC.ParserF;

describe("ListF - Testing functor rules", () => {
  let f = x => x;
  let g = x => 2 * x;

  let actualId = ListFTest.test_id([1]);
  let actualCompose = ListFTest.test_compose(f, g, [1]);
  let actuals = [actualId, actualCompose];

  /* let id = x => 2 * x;
      let (|>>) = (x, f) => ListF.fmap(f, x);
      let x = ListF.fmap(id);
      let xx = [1, 2] |>> id |>> id;
      Js.log2("xx", xx);
     */

  /* let pd = returnP(parseDigit);
     let zz1 = parseDigit <$> string_of_list;
     let zz3 = pd <$> string_of_list;
     let zz4 = pd("12987ABCD") <$> string_of_list;
      */
  /*   let zz = parseDigit("12987ABCD") <$> string_of_list;
        Js.log2("zz1", zz);
       */
  Expect.(test("succeed with ", () =>
            toEqual([(), ()], expect(actuals))
          ));
});

/* describe("ParserF - Testing functor rules", () => {
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