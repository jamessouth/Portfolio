open Jest;
open ReactTestingLibrary;
open JestDom;
open TestUtils;

describe("NavItemErr", () => {
  let rendered = render(<NavItemErr
                          backup="AB"
                          aClass="red"
                          handleClick={(_, _e) => ()}
                          href="about"
                          id=7
                          rel="noref"
                          liClass="green"
                          target="blank"
                        />);

  test("has correct backup text", () => {
    rendered
    |> getByRole(~matcher=`Str("link"), _)
    |> expect
    |> toHaveTextContent(`Str("AB"), _)
  });

  test("has correct aClass", () => {
    let rendered = render(<NavItemErr
                            backup="AB"
                            aClass="red"
                            handleClick={(_, _e) => ()}
                            href="about"
                            id=7
                            rel="noref"
                            liClass="green"
                            target="blank"
                          />);

    rendered
    |> getByRole(~matcher=`Str("link"), _)
    |> expect
    |> toHaveClass(`Str("red"), _)
  });

  test("has correct href", () => {
    let rendered = render(<NavItemErr
                            backup="AB"
                            aClass="red"
                            handleClick={(_, _e) => ()}
                            href="about"
                            id=7
                            rel="noref"
                            liClass="green"
                            target="blank"
                          />);

    rendered
    |> getByRole(~matcher=`Str("link"), _)
    |> expect
    |> toHaveAttribute("href", ~value="about")
  });

  test("has correct rel", () => {
    let rendered = render(<NavItemErr
                            backup="AB"
                            aClass="red"
                            handleClick={(_, _e) => ()}
                            href="about"
                            id=7
                            rel="noref"
                            liClass="green"
                            target="blank"
                          />);

    rendered
    |> getByRole(~matcher=`Str("link"), _)
    |> expect
    |> toHaveAttribute("rel", ~value="noref")
  });

  test("has correct liClass", () => {
    let rendered = render(<NavItemErr
                            backup="AB"
                            aClass="red"
                            handleClick={(_, _e) => ()}
                            href="about"
                            id=7
                            rel="noref"
                            liClass="green"
                            target="blank"
                          />);

    rendered
    |> getByRole(~matcher=`Str("listitem"), _)
    |> expect
    |> toHaveClass(`Str("green"), _)
  });

  test("has correct target", () => {
    let rendered = render(<NavItemErr
                            backup="AB"
                            aClass="red"
                            handleClick={(_, _e) => ()}
                            href="about"
                            id=7
                            rel="noref"
                            liClass="green"
                            target="blank"
                          />);

    rendered
    |> getByRole(~matcher=`Str("link"), _)
    |> expect
    |> toHaveAttribute("target", ~value="blank")
  });

  testPromise("click adds a class", () => {
    let rendered = render(<Footer
                            picPath="error"
                            resPath="test"
                            navLinks=[||]
                          />);

    rendered
    |> findByRole(~matcher=`Str("link"), _)
    |> Promise.map(link => act(() => link |> Event.click))
    |> Promise.flatMap(() => rendered |> findByRole(~matcher=`Str("listitem"), _))
    |> Promise.map(el => expect(el) |> toHaveClass(`Str("selected"), _))
  });
});
