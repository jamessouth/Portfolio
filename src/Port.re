type project = {
    title: string,
    live: option(string),
    code: string,
    path: string,
    obPos: string,
    alt: string,
    text: string,
    liveAria: string,
    codeAria: string,
};

let projects: array(project) = [|
  {
    title: "clean tablet",
    obPos: "center",
    live: Some("http://clean-tablet.herokuapp.com/"),
    code: "https://github.com/jamessouth/clean-tablet",
    alt: "names and words from a game",
    path: "./src/assets/clean.jpg",
    text: "Clean Tablet is based on a game called Blank Slate, a simple and fun party game that my family enjoys. Blank Slate has no online version so I thought it would make a good software project. I wanted to push myself in a new direction, so instead of using Node.js, I built the backend with Go. The frontend is JavaScript and React, and communication with the server is handled with the Gorilla WebSocket package. It is live and playable on Heroku!",
    liveAria: "live site for clean tablet game",
    codeAria: "code for clean tablet project",
  },
  {
    title: "time zones",
    obPos: "left",
    path: "./src/assets/time.jpg",
    text: "Time Zones displays the locations (and optional flag) in a selected time zone, or the user can select a place and receive the zone or zones covering that location. I seeded the MongoDB with a series of Node.js streams, then updated the documents with the flag URLs, then wrote a script to get each URL, download the flag image as base64, and overwrite the URL with the base64 encoded flag. I wrote a GraphQL API to interface with the database and return the results of the user's query to the React frontend. It is also live on Heroku!",
    live: Some("http://timezones.herokuapp.com/"),
    code: "https://github.com/jamessouth/timezones",
    alt: "list of countries in a time zone",
    liveAria: "live site for timezones project",
    codeAria: "code for timezones project",
  },
  {
    title: "portfolio",
    obPos: "left",
    path: "./src/assets/port.jpg",
    text: "Previous versions of my portfolio site were all built with plain JavaScript. I recently started learning ReasonML for a different project and I really enjoy it, so when the need arose to rebuild my portfolio site, I opted to do it with ReasonML + ReasonReact, which is compiled to JavaScript with BuckleScript (now ReScript).",
    code: "https://github.com/jamessouth/portfolio",
    alt: "a snippet of code in an editor",
    codeAria: "code for portfolio project",
    live: None,
    liveAria: "",
  },
  {
    title: "dashboard",
    obPos: "center",
    path: "./src/assets/dash.jpg",
    text: "Dashboard was originally a plain JavaScript school project that I rebuilt with Vue, Vuex, Vue Router, and real data from the World Bank and NASA. I wanted to learn about Progressive Web Apps, so I added a service worker, manifest, icon, and necessary UI changes and it is now an installable PWA!",
    live: Some("https://jamessouth.github.io/dashboard/"),
    code: "https://github.com/jamessouth/dashboard",
    alt: "a doughnut chart",
    liveAria: "live site for web app dashboard project",
    codeAria: "code for web app dashboard project",
  },
  {
    title: "directory",
    obPos: "right",
    path: "./src/assets/dir.jpg",
    text: "Directory was also a plain JavaScript school project. I rebuilt it with React and have also made it into a PWA. I added a sort feature on top of the original filter requirement and I worked a lot on accessibility, including adding ARIA roles and testing with a screen reader (NVDA). I refactored this project to learn React Hooks, including a custom hook, when they were released.",
    live: Some("https://jamessouth.github.io/directory/"),
    code: "https://github.com/jamessouth/directory",
    alt: "employee info cards laid out in a grid",
    liveAria: "live site for employee directory project",
    codeAria: "code for employee directory project",
  },
  {
    title: "15 puzzle generator",
    obPos: "right",
    path: "./src/assets/puzz.jpg",
    text: "15 Puzzle Generator was my first non-school project idea. I originally built it to learn Vue but have since rebuilt it with Angular and TypeScript. It has routing and animated page transitions and I used RxJS for communication among components. I styled it with a mix of Art Deco fonts and Art Nouveau artwork from Czech artist Alfons Mucha. Check out the live puzzle demo!",
    live: Some("https://jamessouth.github.io/fifteen-puzzle-generator/home"),
    code: "https://github.com/jamessouth/fifteen-puzzle-generator",
    alt: "a form, art, and code",
    liveAria: "live site for 15 puzzle generator project",
    codeAria: "code for 15 puzzle generator project",
  },
  {
    title: "face scramble!",
    obPos: "right",
    path: "./src/assets/face.jpg",
    text: "In 2018, I attended a conference where I learned about programming for mobile devices with NativeScript. I had already devised code to play a 15 puzzle for my first portfolio site and my 15 Puzzle Generator project, so I immediately had an idea for what to build with NativeScript. Face Scramble! was also my first foray into Angular and TypeScript. Unfortunately, my computer does not seem to be powerful enough to build this for publication, so for now, on the GitHub repo, I just have a GIF of me playing it on my phone.",
    code: "https://github.com/jamessouth/face-scramble",
    alt: "a 15 puzzle being solved along with moves and elapsed time",
    codeAria: "code for face scramble project",
    live: None,
    liveAria: "",
  },
|];


[@react.component]
let make = () => {


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