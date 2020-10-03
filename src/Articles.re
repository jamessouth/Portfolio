[@bs.val] external fetch: string => Js.Promise.t('a) = "fetch";


type state =
| LoadingImg
| LoadedImg(string);

[@react.component]
let make = () => {
    let (state, setState) = React.useState(() => LoadingImg);

    React.useEffect0(() => {
      Js.Promise.(
        fetch("./src/assets/arts.jpg")
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








    <section id="articles">
        <h2 className="font-forum text-5xl px-0 py-12 text-center tracking-wider border-solid border-eerie-black border-t border-b">
            "ARTICLES"->React.string
        </h2>
        {
            switch (state) {
            | LoadingImg => React.null
            | LoadedImg(src) =>
                <div className="my-16">
                    <Article src obPos=0 link="https://dev.to/jamessouth/generating-shapes-and-images-with-the-css-paint-houdini-api-29c" title="Generating Shapes and Images with the CSS Paint (Houdini) API" alt="a pop art explosion"/>
                    <Article src obPos={-224} link="https://dev.to/jamessouth/generating-knockout-text-with-the-css-paint-houdini-api-2lac" title="Generating Knockout Text with the CSS Paint (Houdini) API" alt="close-up of knockout text with colorful design in background"/>
                </div>
            }
        }


    </section>
};