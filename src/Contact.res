@react.component
let make = (~links: array(Types.contact), ~path, ~id) => {
    let visState = Hook.useVisible(id);

    let picState = Hook.useFetch(visState, path);

    <section id>
        <h2 className="font-forum text-5xl px-0 py-12 text-center tracking-wider border-solid border-eerie-black border-t border-b">
          "CONTACT"->React.string
        </h2>
        <div className="flex flex-row justify-around items-center flex-wrap my-16 xl:mx-auto max-w-cont">
            {switch (picState) {
              | LoadingImg => React.null
              | LoadedImg(src) =>
                  links
                      ->Belt.Array.map(({link, alt, off, w}) =>
                          <Acct link alt off w src key=alt/>)
                      ->React.array;
              | Error(_) =>
                  links
                      ->Belt.Array.map(({link}) =>
                          <a className="m-8 bord" rel="noopener noreferrer" href=link>
                            link->React.string
                          </a>)
                      ->React.array;
              }
            }
            <div className="bg-pe bg-no-repeat bg-center bg-cover m-8 w-56 h-16">
                <a className="h-full block bord focus:border-eerie-black hover:border-eerie-black" ariaLabel="go to project euler" rel="noopener noreferrer" href="https://projecteuler.net"></a>
            </div>
            <div className="bg-cw lg:bg-cw-lg bg-no-repeat bg-center bg-cover m-8 w-48 h-8 lg:w-cw-lg lg:h-10">
                <a className="h-full block bord focus:border-eerie-black hover:border-eerie-black" ariaLabel="go to my codewars profile" rel="noopener noreferrer" href="https://www.codewars.com/users/jamessouth"></a>
            </div>
        </div>
    </section>
};