open Jest;
open ReactTestingLibrary;
open JestDom;

test("About - name appears correctly", () =>
  render(<About />)
  |> getByRole(~matcher=`Str("heading"), _)
  |> expect
  |> toHaveTextContent(`Str("James South"), _)
);

describe("Acct", () => {
  let fakeLink: Portfolio.Contact.contact = {
    link: "hello.org",
    alt: "a smile",
    off: 90,
    w: 78,
  };

  test("has correct alt attr", () => {
    let rendered = render(<Acct
                            link=fakeLink.link
                            alt=fakeLink.alt
                            off=fakeLink.off
                            w=fakeLink.w
                            src="fake.img"
                          />);

    rendered
    |> getByRole(~matcher=`Str("img"), _)
    |> expect
    |> toHaveAttribute("alt", ~value="a smile")
  });

  test("has correct href", () => {
    let rendered = render(<Acct
                            link=fakeLink.link
                            alt=fakeLink.alt
                            off=fakeLink.off
                            w=fakeLink.w
                            src="fake.img"
                          />);

    rendered
    |> getByRole(~matcher=`Str("link"), _)
    |> expect
    |> toHaveAttribute("href", ~value="hello.org")
  });

  test("has correct offset position", () => {
    let rendered = render(<Acct
                            link=fakeLink.link
                            alt=fakeLink.alt
                            off=fakeLink.off
                            w=fakeLink.w
                            src="fake.img"
                          />);

    rendered
    |> getByRole(~matcher=`Str("img"), _)
    |> expect
    |> toHaveStyle(`Obj({"object-position": "90px"}))
  });

  test("has correct width", () => {
    let rendered = render(<Acct
                            link=fakeLink.link
                            alt=fakeLink.alt
                            off=fakeLink.off
                            w=fakeLink.w
                            src="fake.img"
                          />);

    rendered
    |> getByRole(~matcher=`Str("img"), _)
    |> expect
    |> toHaveStyle(`Obj({"width": "78px"}))
  });

  test("has correct src", () => {
    let rendered = render(<Acct
                            link=fakeLink.link
                            alt=fakeLink.alt
                            off=fakeLink.off
                            w=fakeLink.w
                            src="fake.img"
                          />);

    rendered
    |> getByRole(~matcher=`Str("img"), _)
    |> expect
    |> toHaveAttribute("src", ~value="fake.img")
  });

});
