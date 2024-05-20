@react.component
let make = (~picPath, ~resPath, ~navLinks) => {
    let (selectedState, setSelectedState) = React.useState(() => -1);
    let picState = Hook.useFetch(true, picPath);
    let resState = Hook.useFetch(true, resPath);

    let handleClick = (id, _event) => setSelectedState(_ => id);

    <footer className="fixed bg-dark-blue bottom-0 w-screen h-12 z-20">
        <nav className="my-0 h-full">
            <ul
              className="flex justify-around items-center h-full"
            >
                {
                  switch (picState) {
                  | LoadingImg => React.null
                  | LoadedImg(src) =>
                  <>
                    {
                      navLinks
                        ->Belt.Array.mapWithIndex((id, (alt, href, rel, target, aClass, _)) => 
                            <NavItem alt aClass href id rel src target handleClick liClass={selectedState - id == 0 ? "filter-invert-92" : ""} key=alt/>)
                        ->React.array;
                    }
                    {
                      switch (resState) {
                      | Error(_)
                      | LoadingImg => React.null
                      | LoadedImg(href) =>
                          <NavItem
                            alt="CV"
                            aClass="sm:newwindow"
                            href
                            id=4
                            rel="noopener noreferrer"
                            handleClick
                            liClass={selectedState - 4 == 0 ? "filter-invert-92" : ""}
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
                        ->Belt.Array.mapWithIndex((id, (_, href, rel, target, aClass, backup)) => 
                            <NavItemErr backup aClass href id rel liClass={selectedState - id == 0 ? "filter-invert-92" : ""} target handleClick key=href/>)
                        ->React.array;
                    }
                    {
                      switch (resState) {
                      | Error(_)
                      | LoadingImg => React.null
                      | LoadedImg(href) =>
                          <NavItemErr
                            backup="CV"
                            aClass="sm:newwindow"
                            href
                            id=4
                            handleClick
                            rel="noopener noreferrer"
                            liClass={selectedState - 4 == 0 ? "filter-invert-92" : ""}
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
