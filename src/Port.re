[@bs.val] external fetch: string => Js.Promise.t('a) = "fetch";

type project = {
    title: string,
    live: option(string),
    code: string,
    alt: string,
    tech1: string,
    tech2: string,
    liveAria: string,
    codeAria: string,
};

type state =
| LoadingImg
| LoadedImg(string);

let projects: array(project) = [|
  {
    title: "clean tablet",
    live: Some("http://clean-tablet.herokuapp.com/"),
    code: "https://github.com/jamessouth/clean-tablet",
    alt: "names and scores from a game",
    tech1: "go websockets",
    tech2: "react heroku",
    liveAria: "live site for clean tablet game",
    codeAria: "code for clean tablet project",
  },
  {
    title: "time zones",
    tech1: "react mongodb",
    tech2: "node graphql heroku",
    live: Some("http://timezones.herokuapp.com/"),
    code: "https://github.com/jamessouth/timezones",
    alt: "list of countries in a time zone",
    liveAria: "live site for timezones project",
    codeAria: "code for timezones project",
  },
  {
    title: "portfolio",
    tech1: "pwa snowpack a11y paint",
    tech2: "components workers sass",
    code: "https://github.com/jamessouth/portfolio",
    alt: "hovering cubes with images of my websites on each side",
    codeAria: "code for portfolio project",
    live: None,
    liveAria: "",
  },
  {
    title: "dashboard",
    tech1: "pwa vue vuex",
    tech2: "ajax chart.js fp",
    live: Some("https://jamessouth.github.io/dashboard/"),
    code: "https://github.com/jamessouth/dashboard",
    alt: "a doughnut chart",
    liveAria: "live site for web app dashboard project",
    codeAria: "code for web app dashboard project",
  },
  {
    title: "directory",
    tech1: "pwa react a11y",
    tech2: "tdd ajax fp",
    live: Some("https://jamessouth.github.io/directory/"),
    code: "https://github.com/jamessouth/directory",
    alt: "employee info cards laid out in a grid",
    liveAria: "live site for employee directory project",
    codeAria: "code for employee directory project",
  },
  {
    title: "puzzle generator",
    tech1: "angular",
    tech2: "typescript",
    live: Some("https://jamessouth.github.io/fifteen-puzzle-generator/home"),
    code: "https://github.com/jamessouth/fifteen-puzzle-generator",
    alt: "an unsolved sliding block puzzle",
    liveAria: "live site for 15 puzzle generator project",
    codeAria: "code for 15 puzzle generator project",
  },
  {
    title: "face scramble!",
    tech1: "angular typescript",
    tech2: "nativescript",
    code: "https://github.com/jamessouth/face-scramble",
    alt: "a 15 puzzle being solved along with moves and elapsed time",
    codeAria: "code for face scramble project",
    live: None,
    liveAria: "",
  },
  {
    title: "web dev kit",
    live: Some("https://chrome.google.com/webstore/detail/web-dev-kit/geedfiohcopjhgancckdfanhobhfbgmm"),
    code: "https://github.com/jamessouth/webdevkit",
    alt: "a laptop on a desk",
    tech1: "javascript",
    tech2: "chrome extension",
    liveAria: "live site for web dev kit project",
    codeAria: "code for web dev kit project",
  },
  {
    title: "vue-style-lint",
    tech1: "node es6 fp ci tdd",
    tech2: "npm|v1.0.3",
    live: Some("https://www.npmjs.com/package/vue-style-lint"),
    code: "https://github.com/jamessouth/vue-style-lint",
    alt: "output of a computer terminal",
    liveAria: "live site for vue-style-lint project",
    codeAria: "code for vue-style-lint project",
  },
|];






[@react.component]
let make = () => {
    let (state, setState) = React.useState(() => LoadingImg);

    React.useEffect0(() => {
      Js.Promise.(
        fetch("./src/assets/portsprite.jpg")
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

    <section id="port">
        <h2>"Portfolio"->React.string</h2>
        <div className="flex justify-around flex-row items-center flex-wrap w-11/12 m-auto font-corm">
            {switch (state) {
              | LoadingImg => React.null
              | LoadedImg(src) => 
                projects
                    ->Belt.Array.mapWithIndex((i, {title, live, code, alt, tech1, tech2, liveAria, codeAria}) =>
                        <Project title live code alt tech1 tech2 liveAria codeAria i src key=title/>)
                    ->React.array;
              }
            }
        </div>
    </section>
};