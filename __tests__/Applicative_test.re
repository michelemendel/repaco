open Jest;
open ParsersExtended;

describe("Success with applyP", () => {
  /* let fP = returnP([(x, y) => x ++ y]); */
  let xP = returnP(["A"]);
  let expected = returnP(["A"]);
  let actual = applyP(xP, xP);

  /*   Js.log2("-----App:Act", actual);
        Js.log2("-----App:Exp", expected);
       */
  Expect.(test("succeed with ", () =>
            expect(actual) |> toEqual(actual)
          ));
});