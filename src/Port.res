@react.component
let make = (~projects) => {
  <section id="port">
    <h2 className="font-forum text-5xl px-0 py-12 mb-16 text-center tracking-wider">
      {"PORTFOLIO"->React.string}
    </h2>
    {projects
    ->Belt.Array.mapWithIndex((
      i,
      {Data.title: title, live, code, text, liveAria, codeAria, path},
    ) => <Project title live code text liveAria codeAria i key=title path />)
    ->React.array}
  </section>
}
//  alt obPos  className="mx-px"
