[@react.component]
let make = (~selectedState, ~id, ~href, ~src, ~alt) => {


    Js.log2("nav render ", id);

    let off = id * -39;

    <li className={selectedState - id == 0 ? "selected" : ""}>
        

        <a href>
            <img
                className="w-iconw h-iconh object-none"
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