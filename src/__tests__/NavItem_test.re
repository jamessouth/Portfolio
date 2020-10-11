open Jest;
open ReactTestingLibrary;
open JestDom;
open TestUtils;

describe("NavItem", () => {
  let rendered = render(<NavItem
                          alt="home"
                          aClass="red"
                          handleClick={(i, _e) => ()}
                          href="about"
                          id=7
                          rel="noref"
                          liClass="green"
                          src="file"
                          target="blank"
                        />);

  test("has correct alt", () => {
    rendered
    |> getByRole(~matcher=`Str("img"), _)
    |> expect
    |> toHaveAttribute("alt", ~value="home")
  });

  test("has correct aClass", () => {
      let rendered = render(<NavItem
                          alt="home"
                          aClass="red"
                          handleClick={(i, _e) => ()}
                          href="about"
                          id=7
                          rel="noref"
                          liClass="green"
                          src="file"
                          target="blank"
                        />);

    rendered
    |> getByRole(~matcher=`Str("link"), _)
    |> expect
    |> toHaveClass(`Str("red"), _)
  });

  test("has correct href", () => {
      let rendered = render(<NavItem
                          alt="home"
                          aClass="red"
                          handleClick={(i, _e) => ()}
                          href="about"
                          id=7
                          rel="noref"
                          liClass="green"
                          src="file"
                          target="blank"
                        />);

    rendered
    |> getByRole(~matcher=`Str("link"), _)
    |> expect
    |> toHaveAttribute("href", ~value="about")
  });

  test("has correct obj pos", () => {
      let rendered = render(<NavItem
                          alt="home"
                          aClass="red"
                          handleClick={(i, _e) => ()}
                          href="about"
                          id=10
                          rel="noref"
                          liClass="green"
                          src="file"
                          target="blank"
                        />);

    rendered
    |> getByRole(~matcher=`Str("img"), _)
    |> expect
    |> toHaveStyle(`Obj({"object-position": "-390px"}))
  });

  test("has correct rel", () => {
      let rendered = render(<NavItem
                          alt="home"
                          aClass="red"
                          handleClick={(i, _e) => ()}
                          href="about"
                          id=10
                          rel="noref"
                          liClass="green"
                          src="file"
                          target="blank"
                        />);

    rendered
    |> getByRole(~matcher=`Str("link"), _)
    |> expect
    |> toHaveAttribute("rel", ~value="noref")
  });

  test("has correct liClass", () => {
      let rendered = render(<NavItem
                          alt="home"
                          aClass="red"
                          handleClick={(i, _e) => ()}
                          href="about"
                          id=10
                          rel="noref"
                          liClass="green"
                          src="file"
                          target="blank"
                        />);

    rendered
    |> getByRole(~matcher=`Str("listitem"), _)
    |> expect
    |> toHaveClass(`Str("green"), _)
  });

  test("has correct src", () => {
      let rendered = render(<NavItem
                          alt="home"
                          aClass="red"
                          handleClick={(i, _e) => ()}
                          href="about"
                          id=10
                          rel="noref"
                          liClass="green"
                          src="file"
                          target="blank"
                        />);

    rendered
    |> getByRole(~matcher=`Str("img"), _)
    |> expect
    |> toHaveAttribute("src", ~value="file")
  });

  test("has correct target", () => {
      let rendered = render(<NavItem
                          alt="home"
                          aClass="red"
                          handleClick={(i, _e) => ()}
                          href="about"
                          id=10
                          rel="noref"
                          liClass="green"
                          src="file"
                          target="blank"
                        />);

    rendered
    |> getByRole(~matcher=`Str("link"), _)
    |> expect
    |> toHaveAttribute("target", ~value="blank")
  });

});



