[@bs.val] external fetch: string => Js.Promise.t('a) = "fetch";

type state =
| LoadingImg
| LoadedImg(string)
| Error(string);

[@react.component]
let make = () => {
    let (state, setState) = React.useState(() => LoadingImg);

    React.useEffect0(() => {
      Js.Promise.(
        fetch("./src/assets/icons.png")
          |>then_(response => {
              if (response##ok) {
                setState(_previousState => LoadedImg(response##url));
              } else {
                setState(_previousState => Error(""));
                Js.log("failed to fetch " ++ response##url);
              }
              Js.Promise.resolve();
            })
          |>catch(_err => {
            setState(_previousState => Error(""));
            Js.log2("failed to fetch: ", _err);
            Js.Promise.resolve();
          })
          |>ignore
      );
      None;
    });






    <header className="fixed bg-white top-0 w-screen h-12 z-20">
        <nav className="my-0 mx-1 h-full">
            <ul className="font-rob flex justify-between items-center h-full">
                <li>
                    <a className="text-3xl" href="#about">"JS"->React.string</a>
                </li>
                {
                  switch (state) {
                  | LoadingImg => React.null
                  | LoadedImg(src) =>
                    <>
                      <li>
                        <a href="#port">
                          <img className="w-iconw h-iconh object-none object-port" src alt="portfolio icon"/>
                        </a>
                      </li>
                      <li>
                        <a href="#articles">
                          <img className="w-iconw h-iconh object-none object-art" src alt="articles icon"/>
                        </a>
                      </li>
                      <li>
                        <a href="#cont">
                          <img className="w-iconw h-iconh object-none object-cont" src alt="contact icon"/>
                        </a>
                      </li>
                    </>
                  | Error(_) =>
                    <>
                      <li>
                          <a href="#port">"P"->React.string</a>
                      </li>
                      <li>
                          <a href="#articles">"A"->React.string</a>
                      </li>
                      <li>
                          <a href="#cont">"C"->React.string</a>
                      </li>
                    </>
                  }
                }





                <li>
                    <a className="text-3xl sm:newwindow" target="_blank" rel="noopener noreferrer" >"CV"->React.string</a>
                </li>
            </ul>
        </nav>
    </header>
};


