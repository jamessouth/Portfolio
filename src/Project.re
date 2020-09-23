// type project = {
//     title: string,
//     live: option(string),
//     code: string,
//     alt: string,
//     tech1: string,
//     tech2: string,
//     liveAria: option(string),
//     codeAria: string,
// };

[@react.component]
let make = (~title, ~live, ~code, ~alt, ~tech1, ~tech2, ~liveAria, ~codeAria, ~i) => {
    <div>
        <h3>title->React.string</h3>
        <p>tech1->React.string</p>
        <p>tech2->React.string</p>
        <div></div>
        <div>
            <img alt=alt/>
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