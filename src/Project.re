[@react.component]
let make = (~title, ~live, ~code, ~alt, ~tech1, ~tech2, ~liveAria, ~codeAria, ~i, ~src) => {
    let offset = i * -240; // each pic in the sprite is 240x240
    <div className="w-cardw h-cardh border border-solid border-rich-black m-8 flex flex-col items-center justify-around">
        <h3 className="text-3xl font-bold">title->React.string</h3>
        <div></div>
        <img
            src
            className="object-cover w-60 h-60"
            style={ReactDOMRe.Style.make(
                ~objectPosition=offset->string_of_int ++ "px",
                (),
            )}
            alt
        />
        <div className="w-60 flex text-3xl">
            <a className="flex-grow text-center" rel="noopener noreferrer" href=code ariaLabel=codeAria>"code"->React.string</a>
            {
                switch (live) {
                | Some(live) => <a className="flex-grow text-center" rel="noopener noreferrer" href=live ariaLabel=liveAria>"live"->React.string</a>
                | None => React.null
                }
            }
        </div>
        <div className="text-2xl font-bold leading-5 text-center">
            <p>tech1->React.string</p>
            <p>tech2->React.string</p>
        </div>
    </div>
};