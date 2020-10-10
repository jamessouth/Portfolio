[@react.component]
let make = (
    ~backup,
    ~aClass,
    ~handleClick,
    ~href,
    ~id,
    ~rel,
    ~liClass,
    ~target
    ) => {
        <li className=liClass>
            <a
                className={"text-3xl text-white " ++ aClass}
                href
                rel
                target
                onClick=id->handleClick
            >
                backup->React.string
            </a>
        </li>
};