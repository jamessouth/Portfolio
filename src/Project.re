[@react.component]
let make = (~title, ~live, ~code, ~alt, ~text, ~liveAria, ~codeAria, ~path, ~i, ~obPos) => {
    let (isVisible, ref) = ReactIsVisible.useIsVisible(~options={once: true}, ());

    let picState = Hook.useFetch(isVisible, path);

    let flexDir = (index) => {
      switch (index mod 2) {
      | 0 => ""
      | _ => "flex-row-reverse"
      }
    };

    <section
      ref
      className={
        flexDir(i) ++ " flex portrait:flex-col portrait:min-h-screen landscape500:min-h-0"
      }
    >
        <div className="bg-img-bg portrait:h-half-screen wdk1:h-auto w-1/2 portrait:w-auto">
            <img
                src={switch (picState) {
                      | Error(_)
                      | LoadingImg => ""
                      | LoadedImg(src) => src
                }}
                className={
                  "h-full object-cover w-full " ++ "object-" ++ obPos
                }
                alt
            />
        </div>
        <div className="w-1/2 portrait:w-auto">
            <h3 className="text-center my-12 capitalize font-cinz text-3xl">title->React.string</h3>
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