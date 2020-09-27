[@bs.val] external fetch: string => Js.Promise.t('a) = "fetch";

let colors = {
  "typescript": "#2b7489",
  "shell": "#89e051",
  "go": "#00ADD8",
  "vue": "#2c3e50",
  "html": "#e34c26",
  "css": "#563d7c",
  "javascript": "#f1e05a",
};

[@react.component]
let make = (~title, ~live, ~code, ~alt, ~tech1, ~tech2, ~liveAria, ~codeAria, ~i, ~src) => {
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





    <div style={ReactDOMRe.Style.make(
                ~height="400px",
                ~flex="1 0 auto",
                (),
            )} className="m-px bg-red-400 flex justify-center">
        // <h3 className="text-3xl font-bold">title->React.string</h3>
        // <div></div>
        <img
            src="./src/assets/333.jpg"
            className="w-full"
            // style={ReactDOMRe.Style.make(
            //     ~objectPosition=offset->string_of_int ++ "px",
            //     (),
            // )}
            // alt
        />
        // <div className="w-60 flex text-3xl">
        //     <a className="flex-grow text-center hover:bg-dk-sienna hover:text-id-lite" rel="noopener noreferrer" href=code ariaLabel=codeAria>"code"->React.string</a>
        //     {
        //         switch (live) {
        //         | Some(live) => <a className="hover:bg-dk-sienna hover:text-id-lite flex-grow text-center" rel="noopener noreferrer" href=live ariaLabel=liveAria>"live"->React.string</a>
        //         | None => React.null
        //         }
        //     }
        // </div>
        // <div className="text-2xl font-bold leading-5 text-center">
        //     <p>tech1->React.string</p>
        //     <p>tech2->React.string</p>
        // </div>
    </div>
};