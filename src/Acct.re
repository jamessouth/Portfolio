[@react.component]
let make = (~link, ~alt, ~off, ~w, ~src) => {
    <a className="m-8 p-1 bord focus:border-eerie-black hover:border-eerie-black" rel="noopener noreferrer" href=link>
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

// filter: saturate(1.1) drop-shadow(2px 4px 6px #161616);
//     display: block;