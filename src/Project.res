let flexDir = index => {
  switch mod(index, 2) {
  | 0 => "md:flex-row"
  | _ => "md:flex-row-reverse"
  }
}

let borderSide = index => {
  switch mod(index, 2) {
  | 0 => "md:border-r "
  | _ => "md:border-l "
  }
}

// ~alt, ~obPos,
@react.component
let make = (~title, ~live, ~code, ~text, ~liveAria, ~codeAria, ~i, ~path) => {
  // let visState = Hook.useVisible(title);

  // let picState = Hook.useFetch(visState, path);

  <article
    id=title className={flexDir(i) ++ " flex flex-col border-solid border-neutral-900 border-t"}>
    <div
      className={borderSide(i) ++
      `${path} border-solid border-neutral-900 md:w-1/2 bg-contain bg-no-repeat bg-center h-80 md:h-[initial]`}
    />
    <div className={borderSide(i + 1) ++ "border-solid md:w-1/2 border-neutral-900 "}>
      <h3 className="w-11/12 text-center my-12 mx-auto capitalize font-cinz text-3xl">
        {title->React.string}
      </h3>
      <p className="font-gara text-xl mx-auto mb-10 w-4/5"> {text->React.string} </p>
      <div className="mb-10 flex justify-evenly">
        <a
          className="w-20 font-cinz text-lg border border-neutral-900 rounded-full px-2 py-2 text-center hover:bg-neutral-900 hover:text-zinc-100 focus:bg-neutral-900 focus:text-zinc-100"
          rel="noopener noreferrer"
          href=code
          ariaLabel=codeAria>
          {"code"->React.string}
        </a>
        {switch live {
        | Some(live) =>
          <a
            className="w-20 font-cinz text-lg border border-neutral-900 rounded-full px-2 py-2 text-center hover:bg-neutral-900 hover:text-zinc-100 focus:bg-neutral-900 focus:text-zinc-100"
            rel="noopener noreferrer"
            href=live
            ariaLabel=liveAria>
            {"live"->React.string}
          </a>
        | None => React.null
        }}
      </div>
    </div>
  </article>
}
