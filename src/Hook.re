open IntersectionObserver;

[@bs.val] external fetch: string => Js.Promise.t('a) = "fetch";
[@bs.val] external document : Dom.document = "document";
[@bs.send] [@bs.return nullable] external getElementById : (Dom.document, string) => option(Dom.element) = "getElementById";

type fetchState =
| LoadingImg
| LoadedImg(string)
| Error(string);

// type visibleState = 
// | UnSeen
// | Seen;

let useFetch = (start, path) => {
    let (fetchState, setFetchState) = React.useState(() => LoadingImg);

    React.useEffect1(() => {
      if (start) {
        // if (path == "test") {
        //   setFetchState(_ => LoadedImg(path));
        // } else if (path == "error") {
        //   setFetchState(_ => Error(""));
        // } else {
          Js.Promise.(
            fetch(path)
              |>then_(response => {
                  if (response##ok) {
                    setFetchState(_ => LoadedImg(response##url));
                  } else {
                    setFetchState(_ => Error(""));
                    Js.log("failed to fetch " ++ response##url);
                  }
                  Js.Promise.resolve();
                })
              |>catch(_err => {
                setFetchState(_ => Error(""));
                Js.log2("failed to fetch: ", _err);
                Js.Promise.resolve();
              })
              |>ignore
          );
        // }
      }
      None;
    }, [|start|]);

    fetchState;
};

let useVisible = id => {
  let (visibleState, setVisibleState) = React.useState(() => false);
  let obs = React.useRef();


  React.useEffect0(() => {
    let el = document->getElementById(id);

    let ioMapFunc = el => {
      let handler = (. entries, _) => {
            Js.Array.forEach(entry => {
              setVisibleState(_ => IntersectionObserverEntry.isIntersecting(entry));
            }, entries);
          };
          
          let observer = handler->make;
          observe(observer, el);
          
          
    };
    let _ = Belt.Option.map(el, ioMapFunc);
    None;
  });

  visibleState;
};



