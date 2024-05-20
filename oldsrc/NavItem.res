@react.component
let make = (
    ~alt,
    ~aClass,
    ~handleClick,
    ~href,
    ~id,
    ~rel,
    ~liClass,
    ~src,
    ~target
    ) => {
        let off = id * -39;
        <li className={"focus-within:filter-invert-92 hover:filter-invert-92 " ++ liClass}>
            <a className=aClass href rel target onClick=id->handleClick>
                <img
                    className="inline w-iconw h-iconh object-none"
                    src
                    alt
                    style={ReactDOMRe.Style.make(
                        ~objectPosition=off->string_of_int ++ "px",
                        (),
                    )}
                />
            </a>
        </li>
};

