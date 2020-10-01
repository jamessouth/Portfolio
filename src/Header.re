[@bs.val] external fetch: string => Js.Promise.t('a) = "fetch";

type state =
| LoadingImg
| LoadedImg(string);

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
                setState(_previousState => LoadedImg(""));
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





    <header className="fixed bg-blue-300 top-0 w-full h-24 z-20">
        <nav className="my-0 mx-2 h-full">
            <ul className="font-corm flex flex-row justify-around items-center flex-wrap h-full">
                <li>
                    <a href="#about">"JS"->React.string</a>
                </li>
                <li>
                    <a href="#port">"Port"->React.string</a>
                </li>
                <li>
                    <a href="#articles">"Articles"->React.string</a>
                </li>
                <li>
                    <a href="#cont">"Contact"->React.string</a>
                </li>
                <li>
                    <a className="newwindow" target="_blank" rel="noopener noreferrer" >"CV"->React.string</a>
                </li>
            </ul>
        </nav>
    </header>
};


