open Jest;
open ReactTestingLibrary;
open JestDom;

describe("Project", () => {
  let rendered = render(<Project
                          title="myProj"
                          live=Some("here")
                          code="there"
                          alt="cards"
                          text="long string"
                          liveAria="go to live"
                          codeAria="go to code"
                          path="test"
                          i=7
                          obPos="center"
                        />);

  test("displays correct title text", () => {
    rendered
    |> getByRole(~matcher=`Str("heading"), _)
    |> expect
    |> toHaveTextContent(`Str("myProj"), _)
  });

  test("2 links with live site", () => {
    let rendered = render(<Project
                        title="myProj"
                        live=Some("here")
                        code="there"
                        alt="cards"
                        text="long string"
                        liveAria="go to live"
                        codeAria="go to code"
                        path="test"
                        i=7
                        obPos="center"
                      />);

    let linkArr = rendered
                  |> getAllByRole(~matcher=`Str("link"), _);

    render(<p role="para">{linkArr->Array.length->React.int}</p>)
    |> getByRole(~matcher=`Str("para"), _)
    |> expect
    |> toHaveTextContent(`Str("2"), _)
  });

  test("live link has correct href", () => {
    let rendered = render(<Project
                        title="myProj"
                        live=Some("here")
                        code="there"
                        alt="cards"
                        text="long string"
                        liveAria="go to live"
                        codeAria="go to code"
                        path="test"
                        i=7
                        obPos="center"
                      />);

    let linkArr = rendered
                  |> getAllByRole(~matcher=`Str("link"), _);

    linkArr[1]
    |> expect
    |> toHaveAttribute("href", ~value="here")
  });

  test("live link has correct aria label", () => {
    let rendered = render(<Project
                        title="myProj"
                        live=Some("here")
                        code="there"
                        alt="cards"
                        text="long string"
                        liveAria="go to live"
                        codeAria="go to code"
                        path="test"
                        i=7
                        obPos="center"
                      />);

    let linkArr = rendered
                  |> getAllByRole(~matcher=`Str("link"), _);

    linkArr[1]
    |> expect
    |> toHaveAttribute("aria-label", ~value="go to live")
  });

    test("1 link if no live site", () => {
    let rendered = render(<Project
                        title="myProj"
                        live=None
                        code="there"
                        alt="cards"
                        text="long string"
                        liveAria="go to live"
                        codeAria="go to code"
                        path="test"
                        i=7
                        obPos="center"
                      />);

    let linkArr = rendered
                  |> getAllByRole(~matcher=`Str("link"), _);

    render(<p role="para">{linkArr->Array.length->React.int}</p>)
    |> getByRole(~matcher=`Str("para"), _)
    |> expect
    |> toHaveTextContent(`Str("1"), _)
  });

    test("code link has correct href", () => {
    let rendered = render(<Project
                        title="myProj"
                        live=Some("here")
                        code="there"
                        alt="cards"
                        text="long string"
                        liveAria="go to live"
                        codeAria="go to code"
                        path="test"
                        i=7
                        obPos="center"
                      />);

    let linkArr = rendered
                  |> getAllByRole(~matcher=`Str("link"), _);

    linkArr[0]
    |> expect
    |> toHaveAttribute("href", ~value="there")
  });

    test("code link has correct aria label", () => {
    let rendered = render(<Project
                        title="myProj"
                        live=Some("here")
                        code="there"
                        alt="cards"
                        text="long string"
                        liveAria="go to live"
                        codeAria="go to code"
                        path="test"
                        i=7
                        obPos="center"
                      />);

    let linkArr = rendered
                  |> getAllByRole(~matcher=`Str("link"), _);

    linkArr[0]
    |> expect
    |> toHaveAttribute("aria-label", ~value="go to code")
  });

  test("has correct alt", () => {
    let rendered = render(<Project
                        title="myProj"
                        live=Some("here")
                        code="there"
                        alt="cards"
                        text="long string"
                        liveAria="go to live"
                        codeAria="go to code"
                        path="test"
                        i=7
                        obPos="center"
                      />);

    rendered
    |> getByRole(~matcher=`Str("img"), _)
    |> expect
    |> toHaveAttribute("alt", ~value="cards")
  });

  test("displays correct body text", () => {
    let rendered = render(<Project
                            title="myProj"
                            live=Some("here")
                            code="there"
                            alt="cards"
                            text="long string"
                            liveAria="go to live"
                            codeAria="go to code"
                            path="test"
                            i=7
                            obPos="center"
                          />);

    rendered
    |> getByRole(~matcher=`Str("text"), _)
    |> expect
    |> toHaveTextContent(`Str("long string"), _)
  });

  test("even index does not have flex-row-reverse class", () => {
    let rendered = render(<Project
                            title="myProj"
                            live=Some("here")
                            code="there"
                            alt="cards"
                            text="long string"
                            liveAria="go to live"
                            codeAria="go to code"
                            path="test"
                            i=2
                            obPos="center"
                          />);

    rendered
    |> getByRole(~matcher=`Str("region"), _)
    |> expect
    |> not_
    |> toHaveClass(`Str("flex-row-reverse"), _)
  });

  test("odd index does have flex-row-reverse class", () => {
    let rendered = render(<Project
                            title="myProj"
                            live=Some("here")
                            code="there"
                            alt="cards"
                            text="long string"
                            liveAria="go to live"
                            codeAria="go to code"
                            path="test"
                            i=1
                            obPos="center"
                          />);

    rendered
    |> getByRole(~matcher=`Str("region"), _)
    |> expect
    |> toHaveClass(`Str("flex-row-reverse"), _)
  });

  test("has correct object-____ class", () => {
    let rendered = render(<Project
                            title="myProj"
                            live=Some("here")
                            code="there"
                            alt="cards"
                            text="long string"
                            liveAria="go to live"
                            codeAria="go to code"
                            path="test"
                            i=1
                            obPos="center"
                          />);

    rendered
    |> getByRole(~matcher=`Str("img"), _)
    |> expect
    |> toHaveClass(`Str("object-center"), _)
  });
});
