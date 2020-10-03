[@react.component]
let make = (~link, ~title, ~src, ~alt, ~obPos) => {

    <div>
        <div className="w-11/12 h-56 max-w-artw mx-auto bg-img-bg">
            <img
                className="object-none h-56 w-full"
                alt
                src
                style={ReactDOMRe.Style.make(
                    ~objectPosition="0 " ++ obPos->string_of_int ++ "px",
                    (),
                )}
            />
        </div>
        <a
            className="font-bold block mb-12 font-gara w-11/12 mx-auto text-lg hover:bg-eerie-black hover:text-white focus:bg-eerie-black focus:text-white"
            rel="noopener noreferrer"
            href=link
        >
            title->React.string
        </a>
    </div>
};