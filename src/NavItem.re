[@react.component]
let make = (
    ~alt,
    ~cls,
    ~href,
    ~id,
    ~rel,
    ~selectedState,
    ~src,
    ~target
    ) => {
        let off = id * -39;
        <li className={selectedState - id == 0 ? "selected" : ""}>
            <a className=cls href rel target>
                <img
                    className="inline w-iconw h-iconh object-none"
                    src
                    alt
                    style={ReactDOMRe.Style.make(
                        ~objectPosition=off->string_of_int ++ "px",
                        (),
                    )}
                    id=id->string_of_int
                />
            </a>
        </li>
};