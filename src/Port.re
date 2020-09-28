[@bs.val] external fetch: string => Js.Promise.t('a) = "fetch";

type project = {
    title: string,
    live: option(string),
    code: string,
    alt: string,
    text: string,
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
    text: "Clean Tablet is based on a game called Blank Slate, a simple and fun party game that my family enjoys. Blank Slate has no online version so I thought it would make a good software project. I wanted to push myself in a new direction, so instead of using Node.js, I built the backend with Go. The frontend is JavaScript and React, and communication with the server is handled with the Gorilla WebSocket package. It is live and playable on Heroku!",
    tech1: "go websockets",
    tech2: "react heroku",
    liveAria: "live site for clean tablet game",
    codeAria: "code for clean tablet project",
  },
  {
    title: "time zones",
    tech1: "react mongodb",
    tech2: "node graphql heroku",
    text: "Time Zones displays the locations (and optional city/state/national flag) in a selected time zone, or the user can select a place and receive the zone or zones covering that location. I seeded the MongoDB with a series of Node.js streams, then updated the documents with the flag URLs, then wrote a script to get each URL, download the flag image as base64, and overwrite the URL with the base64 encoded flag. I wrote a GraphQL API to interface with the database and return the results of the user's query to the React frontend. It is also live on Heroku!",
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
    text: "Previous versions of my portfolio site were all built with plain JavaScript. I recently started learning ReasonML for a different project and I really enjoy it, so when the need arose to rebuild my portfolio site, I opted to do it with ReasonML/ReasonReact, which is compiled to JavaScript with BuckleScript.",
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
    text: "Dashboard was originally a plain JavaScript school project that I rebuilt with Vue, Vuex, Vue Router, real data, webpack, Babel, and ESLint. I wanted to learn about Progressive Web Apps so I added a service worker, manifest, icon, and necessary UI changes and it is now an installable PWA!",
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
    text: "Directory was also a plain JavaScript school project that I rebuilt with React and have also made into a PWA. I added a sort feature on top of the original filter requirement, and when React Hooks came out I wanted to learn them so I refactored this project to utilize them.",
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
        // <h2>"Portfolio"->React.string</h2>
        // <div className="flex flex-wrap font-corm">
            {switch (state) {
              | LoadingImg => React.null
              | LoadedImg(src) => 
                projects
                    ->Belt.Array.mapWithIndex((i, {title, live, code, alt, tech1, tech2, liveAria, codeAria}) =>
                        <Project title live code alt tech1 tech2 liveAria codeAria i src key=title/>)
                    ->React.array;
              }
            }
        // </div>
    </section>
};