[@bs.val] external fetch: string => Js.Promise.t('a) = "fetch";

type state =
| LoadingImg
| LoadedImg(string)
| Error(string);

let navLinks = [|
  ("JS", "#about", "", "", "", "JS"),
  ("portfolio icon", "#port", "", "", "", "P"),
  ("articles icon", "#articles", "", "", "", "A"),
  ("contact icon", "#cont", "", "", "", "C"),
  ("CV", "", "noopener noreferrer", "_blank", "sm:newwindow", "CV"),
|];

[@react.component]
let make = () => {
    let (picState, setPicState) = React.useState(() => LoadingImg);
    let (selectedState, setSelectedState) = React.useState(() => -1);

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
                if (id != "") {
                  setSelectedState(_ => id);
                }
              }}
            >
                {
                  switch (picState) {
                  | LoadingImg => React.null
                  | LoadedImg(src) =>
                      navLinks
                        ->Belt.Array.mapWithIndex((id, (alt, href, rel, target, cls, _)) => 
                            <NavItem alt cls href id rel selectedState src target key=alt/>)
                        ->React.array;
                  | Error(_) =>
                      navLinks
                        ->Belt.Array.mapWithIndex((id, (_, href, rel, target, cls, backup)) => 
                            <NavItemErr backup cls href id rel selectedState target key=href/>)
                        ->React.array;
                  }
                }
            </ul>
        </nav>
    </footer>
};
