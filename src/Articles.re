[@react.component]
let make = () => {
    let (isVisible, ref) = ReactIsVisible.useIsVisible(~options={once: true}, ());

    let picState =
    switch (isVisible) {
    | false => Hook.useFetch(false, "./src/assets/arts.jpg")
    | true => Hook.useFetch(true, "./src/assets/arts.jpg")
    };

    <section ref id="articles">
        <h2 className="font-forum text-5xl px-0 py-12 text-center tracking-wider border-solid border-eerie-black border-t border-b">
            "ARTICLES"->React.string
        </h2>
        {
            switch (picState) {
            | LoadingImg => React.null
            | Error(src)
            | LoadedImg(src) =>
                <div className="my-16">
                    <Article src obPos=0 link="https://dev.to/jamessouth/generating-shapes-and-images-with-the-css-paint-houdini-api-29c" title="Generating Shapes and Images with the CSS Paint (Houdini) API" alt="a pop art explosion"/>
                    <Article src obPos={-224} link="https://dev.to/jamessouth/generating-knockout-text-with-the-css-paint-houdini-api-2lac" title="Generating Knockout Text with the CSS Paint (Houdini) API" alt="close-up of knockout text with colorful design in background"/>
                </div>
            }
        }
    </section>
};