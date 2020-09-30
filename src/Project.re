[@bs.val] external fetch: string => Js.Promise.t('a) = "fetch";

type picState =
| LoadingImg
| LoadedImg(string);

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
let make = (~title, ~live, ~code, ~alt, ~text, ~liveAria, ~codeAria, ~path, ~obPos) => {
 

    let (picState, setPicState) = React.useState(() => LoadingImg);
    let (langState, setLangState) = React.useState(() => "");

    React.useEffect0(() => {
      Js.Promise.(
        fetch(path)
          |>then_(response => {
              if (response##ok) {
                setPicState(_previousState => LoadedImg(response##url));
              } else {
                setPicState(_previousState => LoadedImg(""));
                Js.log("failed to fetch " ++ response##url);
              }
              Js.Promise.resolve();
            })
          |>catch(_err => {
            Js.log2("failed to fetch: ", _err);
            Js.Promise.resolve();
          })
          |>ignore
      );
      None;
    });

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
                src={switch (picState) {
                      | LoadingImg => ""
                      | LoadedImg(src) => src
                }}
                className={
                  "h-full object-cover wdk1:w-full " ++ "object-" ++ obPos
                }
                alt
            />
        </div>
        <div className="w-1/2 portrait:w-auto">
            <h3 className="text-center m-8 capitalize font-cinz text-3xl">title->React.string</h3>
            <p className="font-gara text-xl mx-auto mb-10 w-4/5">text->React.string</p>
            <div className="mb-10 flex justify-evenly">
              <a className="w-20 font-cinz text-lg border border-eerie-black rounded-full px-2 py-2 text-center hover:bg-eerie-black hover:text-white focus:bg-eerie-black focus:text-white" rel="noopener noreferrer" href=code ariaLabel=codeAria>"code"->React.string</a>
              {
                  switch (live) {
                  | Some(live) => <a className="w-20 font-cinz text-lg border border-eerie-black rounded-full px-2 py-2 text-center hover:bg-eerie-black hover:text-white focus:bg-eerie-black focus:text-white" rel="noopener noreferrer" href=live ariaLabel=liveAria>"live"->React.string</a>
                  | None => React.null
                  }
              }

            </div>
        </div>

    </section>
};