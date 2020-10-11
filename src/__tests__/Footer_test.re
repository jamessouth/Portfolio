open Jest;
open ReactTestingLibrary;
open JestDom;
open TestUtils;

describe("Footer - pic path good", () => {
  test("5 NavItems displayed", () => {
    let rendered = render(<Footer
                            picPath="test"
                            resPath="test"
                          />);

    let navItemArr = rendered
                  |> getAllByRole(~matcher=`Str("img"), _);

    render(<p role="para">{navItemArr->Array.length->React.int}</p>)
    |> getByRole(~matcher=`Str("para"), _)
    |> expect
    |> toHaveTextContent(`Str("5"), _)
  });
});

describe("Footer - pic path error", () => {
  let rendered = render(<Footer
                          picPath="error"
                          resPath="test"
                        />);

  let navItemArr = rendered
                |> getAllByRole(~matcher=`Str("link"), _);

  testAll(
  "5 NavItemErrs displayed",
  Array.to_list(navItemArr),
  link => link
          |> expect
          |> toHaveClass(`Str("text-white"), _)
        );
});

describe("Footer - res path good", () => {
  test("CV link good", () => {
    let rendered = render(<Footer
                            picPath="test"
                            resPath="test"
                          />);

    let navItemArr = rendered
                  |> getAllByRole(~matcher=`Str("link"), _);

    navItemArr[4]
    |> expect
    |> toHaveAttribute("href", ~value="test")
  });
});

describe("Footer - res path error", () => {
  test("4 NavItems displayed", () => {
    let rendered = render(<Footer
                            picPath="test"
                            resPath="error"
                          />);

    let navItemArr = rendered
                  |> getAllByRole(~matcher=`Str("link"), _);

    render(<p role="para">{navItemArr->Array.length->React.int}</p>)
    |> getByRole(~matcher=`Str("para"), _)
    |> expect
    |> toHaveTextContent(`Str("4"), _)
  });
});
