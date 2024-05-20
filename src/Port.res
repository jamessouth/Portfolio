@react.component
let make = (~projects) => {
  <section id="port">
    <h2
      className="font-forum text-5xl px-0 py-12 portrait:mb-16 text-center tracking-wider border-solid border-eerie-black border-t border-b">
      {"PORTFOLIO"->React.string}
    </h2>
    {projects
    ->Belt.Array.mapWithIndex((i, {Data.title: title, live, code, text, liveAria, codeAria}) =>
      <Project title live code text liveAria codeAria i key=title />
    )
    ->React.array}
  </section>
}
//  alt obPos
