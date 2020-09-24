[@react.component]
let make = (~link, ~alt, ~off, ~w, ~src) => {
    <a className="m-8 border-2 border-solid border-transparent" rel="noopener noreferrer" href=link>
            <img
                src
                className="object-none h-16"
                style={ReactDOMRe.Style.make(
                    ~objectPosition=off->string_of_int ++ "px",
                    ~width=w->string_of_int ++ "px",
                    (),
                )}
                alt
            />
    </a>
};