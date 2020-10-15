open IntersectionObserver;

[@bs.val] external fetch: string => Js.Promise.t('a) = "fetch";
[@bs.val] external document : Dom.document = "document";
[@bs.send] [@bs.return nullable] external getElementById : (Dom.document, string) => option(Dom.element) = "getElementById";

type fetchState =
| LoadingImg
| LoadedImg(string)
| Error(string);


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
    let obsCount = React.useRef(0);

    let ioMapFunc = el => {
        let handler = (. entry, observer) => {
            setVisibleState(_ => {
                obsCount.current = obsCount.current + 1;
                if (obsCount.current == 2) {
                    unobserve(observer, el);
                }
                IntersectionObserverEntry.isIntersecting(entry[0]);
            });
        };
        handler->make->observe(el);
    };

    React.useEffect0(() => {
        let el = document->getElementById(id);
        let _ = Belt.Option.map(el, ioMapFunc);
        None;
    });

    visibleState;
};