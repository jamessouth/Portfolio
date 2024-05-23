@react.component
let make = (~link, ~title, ~src, ~alt, ~obPos) => {
  <div className="w-11/12 mx-auto md:flex md:items-center md:mb-8">
    <div className="h-56 mx-auto bg-zinc-100 md:ml-0 md:mr-4 md:flex-shrink-0 lg:mr-16">
      <a
        rel="noopener noreferrer"
        href=link
        className="block focus:filter-article hover:filter-article">
        <img
          className="object-none h-56 w-full"
          alt
          src
          style={ReactDOMRe.Style.make(~objectPosition="0 " ++ obPos->string_of_int ++ "px", ())}
        />
      </a>
    </div>
    <a
      className="font-bold block mb-12 font-gara mx-auto text-lg hover:underline focus:underline md:mb-0 lg:text-2xl lg:mx-0 lg:text-left"
      rel="noopener noreferrer"
      href=link>
      {title->React.string}
    </a>
  </div>
}
