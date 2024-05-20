type contact = {
  link: string,
  alt: string,
  off: int,
  w: int,
}

type project = {
  title: string,
  live: option<string>,
  code: string,
  path: string,
  obPos: string,
  alt: string,
  text: string,
  liveAria: string,
  codeAria: string,
}

let paths = Js.Dict.fromArray([
  ("about", "./assets/wdksmall.png"),
  ("articles", "./assets/arts.jpg"),
  ("contact", "./assets/contsprite.png"),
  ("footPic", "./assets/icons.png"),
  ("footRes", "./assets/resume.pdf"),
])

let navLinks = [
  ("JS", "#about", "", "", "", "JS"),
  ("portfolio icon", "#port", "", "", "", "P"),
  ("articles icon", "#articles", "", "", "", "A"),
  ("contact icon", "#cont", "", "", "", "C"),
]

let projects = [
  {
    title: "clean tablet",
    obPos: "center",
    live: Some("http://clean-tablet.herokuapp.com/"),
    code: "https://github.com/jamessouth/clean-tablet",
    alt: "names and words from a game",
    path: "clean",
    text: "Clean Tablet is based on a game called Blank Slate, a simple and fun party game that my family enjoys. Blank Slate has no online version so I thought it would make a good software project. I wanted to push myself in a new direction, so instead of using Node.js, I built the backend with Go. The frontend is JavaScript and React, and communication with the server is handled with the Gorilla WebSocket package. It is live and playable on Heroku!",
    liveAria: "live site for clean tablet game",
    codeAria: "code for clean tablet project",
  },
  //   {
  //     title: "portfolio",
  //     obPos: "left",
  //     path: "./assets/port.jpg",
  //     text: "My previous portfolio site was made with plain JavaScript and SASS. I wanted to rebuild it with a different stack, so after looking at several languages, I decided on ReasonML + ReasonReact, with Tailwind CSS for styling. I really enjoy Reason; the tooling is good, the community is helpful, and the code quickly compiles to JavaScript with BuckleScript (now ReScript).",
  //     code: "https://github.com/jamessouth/portfolio",
  //     alt: "a snippet of code in an editor",
  //     codeAria: "code for portfolio project",
  //     live: None,
  //     liveAria: "",
  //   },
  //   {
  //     title: "dashboard",
  //     obPos: "center",
  //     path: "./assets/dash.jpg",
  //     text: "Dashboard was originally a plain JavaScript school project that I rebuilt with Vue, Vuex, Vue Router, and real data from the World Bank and NASA. I wanted to learn about Progressive Web Apps, so I added a service worker, manifest, icon, and necessary UI changes and it is now an installable PWA!",
  //     live: Some("https://jamessouth.github.io/dashboard/"),
  //     code: "https://github.com/jamessouth/dashboard",
  //     alt: "a doughnut chart",
  //     liveAria: "live site for web app dashboard project",
  //     codeAria: "code for web app dashboard project",
  //   },
  //   {
  //     title: "directory",
  //     obPos: "right",
  //     path: "./assets/dir.jpg",
  //     text: "Directory was also a plain JavaScript school project. I rebuilt it with React and also made it into a PWA. I added a sort feature on top of the original filter requirement and I worked a lot on accessibility, including adding ARIA roles and testing with a screen reader (NVDA). I refactored this project to learn React Hooks when they were released.",
  //     live: Some("https://jamessouth.github.io/directory/"),
  //     code: "https://github.com/jamessouth/directory",
  //     alt: "employee info cards laid out in a grid",
  //     liveAria: "live site for employee directory project",
  //     codeAria: "code for employee directory project",
  //   },
  //   {
  //     title: "15 puzzle generator",
  //     obPos: "right",
  //     path: "./assets/puzz.jpg",
  //     text: "15 Puzzle Generator was my first non-school project idea. I originally built it to learn Vue but have since rebuilt it with Angular and TypeScript. It has routing and animated page transitions and I used RxJS for communication among components. I styled it with a mix of Art Deco fonts and Art Nouveau artwork from Czech artist Alfons Mucha. Check out the live puzzle demo!",
  //     live: Some("https://jamessouth.github.io/fifteen-puzzle-generator/home"),
  //     code: "https://github.com/jamessouth/fifteen-puzzle-generator",
  //     alt: "a form, art, and code",
  //     liveAria: "live site for 15 puzzle generator project",
  //     codeAria: "code for 15 puzzle generator project",
  //   },
  //   {
  //     title: "face scramble!",
  //     obPos: "right",
  //     path: "./assets/face.jpg",
  //     text: "In 2018, I attended a conference where I learned about programming for mobile devices with NativeScript. I had already devised code to play a 15 puzzle for my first portfolio site and my 15 Puzzle Generator project, so I immediately had an idea for what to build with NativeScript. Face Scramble! was also my first foray into Angular and TypeScript. Unfortunately, my computer does not seem to be powerful enough to build this for publication, so for now, on the GitHub repo, I just have a GIF of me playing it on my phone.",
  //     code: "https://github.com/jamessouth/face-scramble",
  //     alt: "a 15 puzzle being solved along with moves and elapsed time",
  //     codeAria: "code for face scramble project",
  //     live: None,
  //     liveAria: "",
  //   },
]

let links = [
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
]
