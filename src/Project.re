[@react.component]
let make = (~title, ~live, ~code, ~alt, ~tech1, ~tech2, ~liveAria, ~codeAria, ~i, ~imgSrc) => {
    let offset = i * -288; // each pic of the sprite is 288x288
    <div className="w-cardw h-cardh bg-yellow-crayola m-6">
        <h3>title->React.string</h3>
        <p>tech1->React.string</p>
        <p>tech2->React.string</p>
        <div></div>
        <div>
            <img
            src=imgSrc
            className="object-cover w-full h-full"
            style={ReactDOMRe.Style.make(
                ~objectPosition=offset->string_of_int ++ "px",
                (),
            )}
            alt=alt/>
            <a rel="noopener noreferrer" href=code ariaLabel=codeAria>"code"->React.string</a>
            {
                switch (live) {
                | Some(live) => <a rel="noopener noreferrer" href=live ariaLabel=liveAria>"live"->React.string</a>
                | None => React.null
                }
            }
        </div>
    </div>
};