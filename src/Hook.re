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

  let el = document->getElementById(id);

  let ioMapFunc = el => {
    let handler = (. entries, _) => {
      Js.log(entries->Array.length);
          Js.Array.forEach(entry => {
            Js.log(entry);
            switch (IntersectionObserverEntry.isIntersecting(entry)) {
            | true => setVisibleState(_ => true);
            | false => setVisibleState(_ => false);
            }
            // Js.log(IntersectionObserverEntry.isIntersecting(entry));
            // Js.log(IntersectionObserverEntry.target(entry));
          }, entries);

          // IntersectionObserver.unobserve(observer, el);
        };

        let observer = make(handler);
        observe(observer, el);
  };

  let _ = Belt.Option.map(el, ioMapFunc);
  visibleState;
};



