[@bs.val] external fetch: string => Js.Promise.t('a) = "fetch";

type contact = {
    link: string,
    alt: string,
    off: int,
    w: int,
};








type state =
| LoadingImg
| LoadedImg(string);

let links: array(contact) = [|
  {
    link: "mailto:jamesdanielsouth@outlook.com",
    alt: "open your email client to email me",
    off: 0,
    w: 78,
  },
  {
    link: "https://github.com/jamessouth",
    alt: "go to my github",
    off: -78,
    w: 64,
  },
  {
    link: "https://app.pluralsight.com/profile/jamessouth",
    alt: "go to my pluralsight profile",
    off: -142,
    w: 196,
  },
  {
    link: "https://stackoverflow.com/users/9996080/james-south?tab=profile",
    alt: "go to my stack overflow profile",
    off: -338,
    w: 54,
  },
  {
    link: "https://twitter.com/dsouthbot",
    alt: "go to my twitter",
    off: -392,
    w: 78,
  },
  {
    link: "https://exercism.io/profiles/jamessouth",
    alt: "go to my exercism profile",
    off: -470,
    w: 130,
  },
  {
    link: "https://dev.to/jamessouth",
    alt: "go to my dev community profile",
    off: -600,
    w: 64,
  },
|];

[@react.component]
let make = () => {
    let (state, setState) = React.useState(() => LoadingImg);

    React.useEffect0(() => {
      Js.Promise.(
        fetch("./src/assets/contsprite.png")
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


    <section id="cont">
        <h2 className="font-forum">
          "CONTACT"->React.string
        </h2>
        <div className="flex flex-row justify-around items-center flex-wrap xl:m-auto max-w-cont">
            {switch (state) {
              | LoadingImg => React.null
              | LoadedImg(src) => 
                links
                    ->Belt.Array.map(({link, alt, off, w}) =>
                        <Acct link alt off w src key=off->string_of_int/>)
                    ->React.array;
              }
            }
            // <div className="bg-pe bg-no-repeat bg-center bg-cover m-8 bord w-56 h-16">
            //     <a className="h-full block bord" ariaLabel="go to project euler" rel="noopener noreferrer" href="https://projecteuler.net"></a>
            // </div>
            // <div className="bg-cw lg:bg-cw-lg bg-no-repeat bg-center bg-cover m-8 bord w-48 h-8 lg:w-cw-lg lg:h-10">
            //     <a className="h-full block bord" ariaLabel="go to my codewars profile" rel="noopener noreferrer" href="https://www.codewars.com/users/jamessouth"></a>
            // </div>
        </div>
    </section>
};