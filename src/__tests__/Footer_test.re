open Jest;
open ReactTestingLibrary;
open JestDom;

describe("Footer", () => {
  
  let rendered = render(<Article
                          link="blog.org"
                          alt="a book"
                          obPos={-90}
                          title="my article"
                          src="art.png"
                        />);

  test("a click updates the state properly", () => {
    rendered
    |> getByRole(~matcher=`Str("img"), _)
    |> expect
    |> toHaveAttribute("alt", ~value="a book")
  });

  // let linkArr = rendered
  //               |> getAllByRole(~matcher=`Str("link"), _);

  // testAll(
  //   "links have correct href",
  //   Array.to_list(linkArr),
  //   link => link
  //           |> expect
  //           |> toHaveAttribute("href", ~value="blog.org")
  //         );

  // test("has correct title", () => {
  //   linkArr[1]
  //   |> expect
  //   |> toHaveTextContent(`Str("my article"), _)
  // });

  // test("has correct src", () => {
  //   let rendered = render(<Article
  //                           link="blog.org"
  //                           alt="a book"
  //                           obPos={-90}
  //                           title="my article"
  //                           src="art.png"
  //                         />);

  //   rendered
  //   |> getByRole(~matcher=`Str("img"), _)
  //   |> expect
  //   |> toHaveAttribute("src", ~value="art.png")
  // });

  // test("has correct offset position", () => {
  //   let rendered = render(<Article
  //                           link="blog.org"
  //                           alt="a book"
  //                           obPos={-90}
  //                           title="my article"
  //                           src="art.png"
  //                         />);

  //   rendered
  //   |> getByRole(~matcher=`Str("img"), _)
  //   |> expect
  //   |> toHaveStyle(`Obj({"object-position": "0 -90px"}))
  // });
});
