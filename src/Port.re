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

let fallback = "data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAPAAAADwBAMAAADMe/ShAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAwUExURf///wAICIy1vYy1Oim1vSm1OowxrSkxrXMxKd46vd46Ot6tvd6tOt7vhN73///v//AEph8AAAAJcEhZcwAADsMAAA7DAcdvqGQAAANeSURBVHja7ZrBattAEIbX8kUgsDMJBEHAiXIoBkOIewr0ZfookXMJFNpXidNLIdBnsd1LIZf0BUplx5Z2ZlfKxtZqD/2/U+yM9pN2V6vRrBUAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAMBmqMCR0oYLQoyMVhIxuVRDyQF2dEKkgxHSsgjAPNbcwxF2xpHMVhCldqxAMiBa+2l7dE9Hdlf2fEaX8i+HjTU5r7meT95xSTBWbJTjJt59m1vg/NGKfP+RaAzR72Fu80lqxxfMnRDIlwWRP8S+SPSAg0i5q0zvp7Onv87g86Mte4oidfWqGsyEerL2fXv+uzvjrHuJI9Jt5yT06qz5kuqbq9It3i0c5pROt1yxrlD7E69OsTmPZcNRb4qJziwEcavPUuD/0J8S8iF/YGnKa2ly8aXVKtb3GhriI+2ZtyCkzYuLXdrL6JtgTIqP0xdqQU1/r4hMlxfKRn+nfxGwC97UBc/Dq8bvr08QjEc2TgKe6hg4Xn/HgpiRAb8hlzdbjt8+7ee1oNSUB+hrgMq2j94ib8jy9IZclpFl8woOb8rx2xXx+Jk2j51Mcyx4oWF3e3F3+PFB88YZ4adxej9vlNb2yXUFr4qlcyX5UkbO+P/FA3ieatwj1J5Z5XnmNH5+/s8yLPrcr7vGFrMwKT5VMvloWi0pAGTba/tebmA9xUgYdGQ21KxZDvOxM3OMrdzWdbj2L+RBrx/kW8yeEkWL1fYkjngQsDxX3XcUiCcg6E4skIG8SuyyZzmKRBHQmLtaLF/04OlQcO4plEtCZeC6SgLwrcS6SAB/izCI2koCuxH35QpT5FZ/uwpbybaZx5XLJMh3FxnZA7Fe869+h8T4U+e3qtNQY77xSbFTqWhH3zNfETGhyL2LLjk/VtZuHB8ux2xPb5kt5iev5ziqCTpsWTuLIVgkoj0wfBmP+JiFuvTfF13VieyWAvT0c6w25lH2cxJm18/SsKV3oDbmUfSx3gSmuqQT8LuNOHnjBzGEF6ZniqRTXFnt2U2omrqCtLbH6Yk8yzim9M4s8L+2I56F2fPJAOz6Jxx2fRmzFnk4wiz0dMQ30m4ChY62/dSK3wnf7BNswjkP97ENdKgAAAAAAAAAAAAAAAAAAAAAAAAAAAMD/gVL/AD6jHEm7rYqjAAAAAElFTkSuQmCC";



[@react.component]
let make = () => {
    let (state, setState) = React.useState(() => LoadingImg);

    React.useEffect0(() => {
      Js.Promise.(
        fetch("./src/assets/ports8prite.jpg")
          |>then_(response => {
            if (response##ok) {
              response##url;
            } else {
              _ => Js.Promise.reject;
              ()
            }
            Js.log(response)
            })
          |>then_(imgURL => {
            Js.log("goood")
              setState(_previousState => LoadedImg(imgURL));
              Js.Promise.resolve();
          })
          |>catch(_err => {
            setState(_previousState => LoadedImg(fallback));
            Js.Promise.resolve();
          })
          |>ignore
      );
      None;
    });

    <section id="port">
        <h2>"Portfolio"->React.string</h2>
        <div>
            {switch (state) {
              | LoadingImg => React.null
              | LoadedImg(imgSrc) => 
                projects
                    ->Belt.Array.mapWithIndex((i, {title, live, code, alt, tech1, tech2, liveAria, codeAria}) =>
                        <Project title live code alt tech1 tech2 liveAria codeAria i imgSrc key=title/>)
                    ->React.array;
              }
            }
        </div>
    </section>
};