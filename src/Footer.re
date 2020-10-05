[@bs.val] external fetch: string => Js.Promise.t('a) = "fetch";

type state =
| LoadingImg
| LoadedImg(string)
| Error(string);

[@react.component]
let make = () => {
    let (picState, setPicState) = React.useState(() => LoadingImg);
    let (selectedState, setSelectedState) = React.useState(() => -1);

    Js.log("foot render");
    
    React.useEffect1(() => {
      Js.log2("ff", selectedState);
      None;
    }, [|selectedState|]);

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




    <footer className="fixed bg-dark-blue bottom-0 w-screen h-12 z-20">
        <nav className="my-0 h-full">
            <ul
              className="flex justify-around items-center h-full"
              onClick={event => {
                let id = ReactEvent.Mouse.target(event)##id;
                // Js.log(id);
                if (id != "") {
                  setSelectedState(_ => id);
                }
              }}
            >
                {
                  switch (picState) {
                  | LoadingImg => React.null
                  | LoadedImg(src) =>
                    <>
                <NavItem
                  alt="JS"
                  selectedState
                  src
                  id=0
                  href="#about"
                />
                <NavItem
                  alt="portfolio icon"
                  selectedState
                  src
                  id=1
                  href="#port"
                />
                <NavItem
                  alt="articles icon"
                  selectedState
                  src
                  id=2
                  href="#articles"
                />
                <NavItem
                  alt="contact icon"
                  selectedState
                  src
                  id=3
                  href="#cont"
                />


                <li className={selectedState - 4 == 0 ? "selected" : ""}>
                    <a className="sm:newwindow" target="_blank" rel="noopener noreferrer">
                    


                      <img
                          className="w-iconw h-iconh object-none inline"
                          src
                          alt="CV"
                          style={ReactDOMRe.Style.make(
                              ~objectPosition={4 * -39}->string_of_int ++ "px",
                              (),
                          )}
                          id="4"
                      />

                    </a>
                </li>

                    </>
                  | Error(_) =>
                    <>
                      <li className={selectedState - 0 == 0 ? "selected" : ""}>
                          <a id="0" className="text-3xl text-white" href="#about">"JS"->React.string</a>
                      </li>
                      <li className={selectedState - 1 == 0 ? "selected" : ""}>
                          <a id="1" className="text-3xl text-white" href="#port">"P"->React.string</a>
                      </li>
                      <li className={selectedState - 2 == 0 ? "selected" : ""}>
                          <a id="2" className="text-3xl text-white" href="#articles">"A"->React.string</a>
                      </li>
                      <li className={selectedState - 3 == 0 ? "selected" : ""}>
                          <a id="3" className="text-3xl text-white" href="#cont">"C"->React.string</a>
                      </li>
                      <li className={selectedState - 4 == 0 ? "selected" : ""}>
                          <a id="4" className="sm:newwindow text-3xl text-white" target="_blank" rel="noopener noreferrer">"CV"->React.string</a>
                      </li>
                    </>
                  }
                }

            </ul>
        </nav>
    </footer>
};


