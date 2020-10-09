open Jest;
open ReactTestingLibrary;
open JestDom;

// test("About - name appears correctly", () =>
//   render(<About />)
//   |> getByRole(~matcher=`Str("heading"))
//   |> expect
//   |> toHaveTextContent(`Str("James South"))
// );

describe("Article", () => {
  // test("has correct alt attr", () => {
  //   let rendered = render(<Article
  //                           link="blog.org"
  //                           alt="a book"
  //                           obPos={-90}
  //                           title="my article"
  //                           src="art.png"
  //                         />);

  //   rendered
  //   |> getByRole(~matcher=`Str("img"))
  //   |> expect
  //   |> toHaveAttribute("alt", ~value="a book")
  // });

  test("has correct href", () => {
    let rendered = render(<Article
                            link="blog.org"
                            alt="a book"
                            obPos={-90}
                            title="my article"
                            src="art.png"
                          />);

    let a = rendered
    |> getAllByRole(~matcher=`Str("link"), _);

    a[0]
    |> expect
    |> toHaveAttribute("href", ~value="blog9.org")
  });

  // test("has correct object position", () => {
  //   let rendered = render(<Article
  //                           link="blog.org"
  //                           alt="a book"
  //                           obPos={-90}
  //                           title="my article"
  //                           src="art.png"
  //                         />);

  //   rendered
  //   |> getByRole(~matcher=`Str("img"))
  //   |> expect
  //   |> toHaveStyle(`Obj({"object-position": "90px"}))
  // });

  // test("has correct title", () => {
  //   let rendered = render(<Article
  //                           link="blog.org"
  //                           alt="a book"
  //                           obPos={-90}
  //                           title="my article"
  //                           src="art.png"
  //                         />);

  //   rendered
  //   |> getByRole(~matcher=`Str("img"))
  //   |> expect
  //   |> toHaveStyle(`Obj({"width": "78px"}))
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
  //   |> getByRole(~matcher=`Str("img"))
  //   |> expect
  //   |> toHaveAttribute("src", ~value="fake.img")
  // });

});
