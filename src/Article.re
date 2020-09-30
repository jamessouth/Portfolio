[@react.component]
let make = (~link, ~title, ~src, ~alt, ~obPos) => {

    <div>
        <a
            className="underline block mb-10 text-center font-gara w-4/5 mx-auto text-2xl hover:bg-eerie-black hover:text-white focus:bg-eerie-black focus:text-white"
            rel="noopener noreferrer"
            href=link
        >
            title->React.string
        </a>
        <div className="w-11/12 h-12 max-w-artw mx-auto mb-10 bg-img-bg">
            <img
                className="object-none h-12 w-full"
                alt
                src
                style={ReactDOMRe.Style.make(
                    ~objectPosition="0 " ++ obPos->string_of_int ++ "px",
                    (),
                )}
            />
        </div>
    </div>
};