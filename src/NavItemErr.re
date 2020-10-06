[@react.component]
let make = (
    ~backup,
    ~cls,
    ~href,
    ~id,
    ~rel,
    ~selectedState,
    ~target
    ) => {
        <li className={selectedState - id == 0 ? "selected" : ""}>
            <a
                className={"text-3xl text-white " ++ cls}
                href
                rel
                target
                id=id->string_of_int
            >
                backup->React.string
            </a>
        </li>
};