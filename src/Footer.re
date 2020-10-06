let navLinks = [|
  ("JS", "#about", "", "", "", "JS"),
  ("portfolio icon", "#port", "", "", "", "P"),
  ("articles icon", "#articles", "", "", "", "A"),
  ("contact icon", "#cont", "", "", "", "C"),
|];

[@react.component]
let make = () => {
    let (selectedState, setSelectedState) = React.useState(() => -1);
    let picState = Hook.useFetch("./src/assets/icons.png");
    let resState = Hook.useFetch("./src/assets/resume.pdf");

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
                  <>
                    {
                      navLinks
                        ->Belt.Array.mapWithIndex((id, (alt, href, rel, target, cls, _)) => 
                            <NavItem alt cls href id rel selectedState src target key=alt/>)
                        ->React.array;
                    }
                    {
                      switch (resState) {
                      | Error(_)
                      | LoadingImg => React.null
                      | LoadedImg(href) =>
                          <NavItem
                            alt="CV"
                            cls="sm:newwindow"
                            href
                            id=4
                            rel="noopener noreferrer"
                            selectedState
                            src
                            target="_blank"
                            key="CV"
                          />;
                      }
                    }
                  </>
                  | Error(_) =>
                  <>
                    {
                      navLinks
                        ->Belt.Array.mapWithIndex((id, (_, href, rel, target, cls, backup)) => 
                            <NavItemErr backup cls href id rel selectedState target key=href/>)
                        ->React.array;
                    }
                    {
                      switch (resState) {
                      | Error(_)
                      | LoadingImg => React.null
                      | LoadedImg(href) =>
                          <NavItemErr
                            backup="CV"
                            cls="sm:newwindow"
                            href
                            id=4
                            rel="noopener noreferrer"
                            selectedState
                            target="_blank"
                            key=href
                          />;
                      }
                    }
                  </>
                  }
                }
            </ul>
        </nav>
    </footer>
};
