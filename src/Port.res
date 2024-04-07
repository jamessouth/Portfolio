[@react.component]
let make = (~projects: array(Types.project)) => {
    <section id="port">
          <h2 className="font-forum text-5xl px-0 py-12 portrait:mb-16 text-center tracking-wider border-solid border-eerie-black border-t border-b">
            "PORTFOLIO"->React.string
          </h2>
          {
              projects
                  ->Belt.Array.mapWithIndex((i, {title, live, code, alt, text, liveAria, codeAria, path, obPos}) =>
                      <Project title live code alt text liveAria codeAria path i obPos key=title/>)
                  ->React.array;
          }
    </section>
};