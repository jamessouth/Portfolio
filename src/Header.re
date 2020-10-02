[@bs.val] external fetch: string => Js.Promise.t('a) = "fetch";

type state =
| LoadingImg
| LoadedImg(string)
| Error(string);

[@react.component]
let make = () => {
    let (picState, setPicState) = React.useState(() => LoadingImg);
    let (selectedState, setSelectedState) = React.useState(() => "");

    React.useEffect0(() => {
      Js.Promise.(
        fetch("./src/assets/icons.png")
          |>then_(response => {
              if (response##ok) {
                setPicState(_ => LoadedImg(response##url));
              } else {
                setPicState(_ => Error(""));
                Js.log("failed to fetch " ++ response##url);
              }
              Js.Promise.resolve();
            })
          |>catch(_err => {
            setPicState(_ => Error(""));
            Js.log2("failed to fetch: ", _err);
            Js.Promise.resolve();
          })
          |>ignore
      );
      None;
    });




    <header className="fixed bg-dark-blue bottom-0 w-screen h-12 z-20">
        <nav className="my-0 mx-1 h-full">
            <ul
              className="font-rob flex justify-between items-center h-full"
              onClick={event => {
                let id = ReactEvent.Mouse.target(event)##id;
                Js.log(id);
                if (id != "") {
                  setSelectedState(_ => id);
                }
              }}
            >
                <li className={selectedState == "1" ? "selected" : ""}>
                    <a id="1" className="text-3xl text-white" href="#about">"JS"->React.string</a>
                </li>
                {
                  switch (picState) {
                  | LoadingImg => React.null
                  | LoadedImg(src) =>
                    <>
                      <li className={selectedState == "2" ? "selected" : ""}>
                        <a href="#port">
                          <img id="2" className="w-iconw h-iconh object-none object-port" src alt="portfolio icon"/>
                        </a>
                      </li>
                      <li className={selectedState == "3" ? "selected" : ""}>
                        <a href="#articles">
                          <img id="3" className="w-iconw h-iconh object-none object-art" src alt="articles icon"/>
                        </a>
                      </li>
                      <li className={selectedState == "4" ? "selected" : ""}>
                        <a href="#cont">
                          <img id="4" className="w-iconw h-iconh object-none object-cont" src alt="contact icon"/>
                        </a>
                      </li>
                    </>
                  | Error(_) =>
                    <>
                      <li className={selectedState == "2" ? "selected" : ""}>
                          <a id="2" className="text-3xl text-white" href="#port">"P"->React.string</a>
                      </li>
                      <li className={selectedState == "3" ? "selected" : ""}>
                          <a id="3" className="text-3xl text-white" href="#articles">"A"->React.string</a>
                      </li>
                      <li className={selectedState == "4" ? "selected" : ""}>
                          <a id="4" className="text-3xl text-white" href="#cont">"C"->React.string</a>
                      </li>
                    </>
                  }
                }



                <li className={selectedState == "5" ? "selected" : ""}>
                    <a id="5" className="text-3xl text-white sm:newwindow" target="_blank" rel="noopener noreferrer" >"CV"->React.string</a>
                </li>
            </ul>
        </nav>
    </header>
};


