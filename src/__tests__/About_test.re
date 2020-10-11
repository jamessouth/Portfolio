open Jest;
open ReactTestingLibrary;
open JestDom;

describe("About", () => {
  test("name appears correctly", () => {
    let rendered = render(<About path="test"/>);

    rendered
    |> getByRole(~matcher=`Str("heading"), _)
    |> expect
    |> toHaveTextContent(`Str("James South"), _)
  });

  test("has correct src", () => {
    let rendered = render(<About path="test"/>);

    rendered
    |> getByRole(~matcher=`Str("img"), _)
    |> expect
    |> toHaveAttribute("src", ~value="test")
  });

  test("has correct src on error", () => {
    let rendered = render(<About path="error"/>);

    rendered
    |> getByRole(~matcher=`Str("img"), _)
    |> expect
    |> toHaveAttribute("src", ~value="")
  });
});
