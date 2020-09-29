[@bs.val] external fetch: string => Js.Promise.t('a) = "fetch";

let colors = {
  "typescript": "#2b7489",
  "other": "#ededed",
  "go": "#00ADD8",
  "vue": "#2c3e50",
  "html": "#e34c26",
  "css": "#563d7c",
  "javascript": "#f1e05a",
  "reason": "#ff5847",
};

[@react.component]
let make = (~title, ~live, ~code, ~alt, ~text, ~liveAria, ~codeAria, ~i, ~src) => {
    let offset = i * -240; // each pic in the sprite is 240x240

    let (state, setState) = React.useState(() => "");

    React.useEffect0(() => {

        // Js.Promise.(
        //     fetch("http://localhost:8000/?id=" ++ inp)
        //     |> then_(response => response##json())
        //     |> then_(jsonResponse => {
        //         Js.log2("re5sss", jsonResponse);
        //         dispatch(LoadedData(jsonResponse));
        //         Js.Promise.resolve();
        //         })
        //     |> catch(_err => {
        //         dispatch(ErrorFetchingData);
        //         Js.Promise.resolve();
        //         })
        //     |> ignore
        // );
        None;
    });






    <section className="flex flex-row-reverse portrait:flex-col min-h-screen">
        // <h3 className="text-3xl font-bold">title->React.string</h3>
        <div className="bg-img-bg h-half-screen wdk1:h-auto w-1/2 portrait:w-auto">
            <img
                src
                className="max-w-none h-full object-cover wdk1:w-full"
                style={ReactDOMRe.Style.make(
                    ~objectPosition=offset->string_of_int ++ "px",
                    (),
                )}
                alt
            />
        </div>
        <div className="w-1/2 portrait:w-auto">
            <h3 className="text-center">title->React.string</h3>
            <p>text->React.string</p>
            <a className="flex-grow text-center hover:bg-dk-sienna hover:text-id-lite" rel="noopener noreferrer" href=code ariaLabel=codeAria>"code"->React.string</a>
            {
                switch (live) {
                | Some(live) => <a className="hover:bg-dk-sienna hover:text-id-lite flex-grow text-center" rel="noopener noreferrer" href=live ariaLabel=liveAria>"live"->React.string</a>
                | None => React.null
                }
            }



        </div>

    </section>
};