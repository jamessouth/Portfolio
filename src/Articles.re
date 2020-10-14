[@bs.val] external document : Dom.document = "document";
[@bs.send.pipe : Dom.document ] [@bs.return nullable] external querySelector : string => option(Dom.element) = "querySelector";

[@react.component]
let make = (~path) => {


    let el = switch (document |> querySelector("#articles")) {
        | Some(el) => el
        | None => 
    }
    

    
    let handler =
  (. entries, observer) => {
    Js.Array.forEach(entry => {
      Js.log(IntersectionObserverEntry.time(entry));
      Js.log(IntersectionObserverEntry.rootBounds(entry));
      Js.log(IntersectionObserverEntry.boundingClientRect(entry));
      Js.log(IntersectionObserverEntry.intersectionRect(entry));
      Js.log(IntersectionObserverEntry.isIntersecting(entry));
      Js.log(IntersectionObserverEntry.intersectionRatio(entry));
      Js.log(IntersectionObserverEntry.target(entry));
    }, entries);

    IntersectionObserver.unobserve(observer, el);
  };

let observer =
  IntersectionObserver.make(handler);

IntersectionObserver.observe(observer, el);
IntersectionObserver.unobserve(observer, el);
IntersectionObserver.observe(observer, el);
IntersectionObserver.disconnect(observer);





    let picState = Hook.useFetch(true, path);

    <section id="articles">
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