[@react.component]
let make = (~link, ~title, ~src, ~alt, ~obPos) => {

    <div className="w-11/12 max-w-artw mx-auto wdk1:max-w-none">
        <div className="h-56 mx-auto bg-img-bg wdk1:max-w-artw">
            <a
                rel="noopener noreferrer"
                href=link
            >
                <img
                    className="object-none h-56 w-full"
                    alt
                    src
                    style={ReactDOMRe.Style.make(
                        ~objectPosition="0 " ++ obPos->string_of_int ++ "px",
                        (),
                    )}
                />
            </a>
        </div>
        <a
            className="font-bold block mb-12 font-gara mx-auto text-lg hover:underline focus:underline wdk1:text-center"
            rel="noopener noreferrer"
            href=link
        >
            title->React.string
        </a>
    </div>
};