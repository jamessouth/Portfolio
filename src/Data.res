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
    live: Some("https://ct.dsouth.org/"),
    code: "https://github.com/jamessouth/clean-tablet",
    path: "bg-clean",
    text: "Clean Tablet is my clone of a game called Blank Slate, a simple and fun party game that my family enjoys. After playing it for the first time, I thought that it would make a good software project. I built the back-end with Go, which I didn't know at the time, and the front-end with React. I recently hosted it on Back4App, so it is live and playable!",
    liveAria: "live site for clean tablet game",
    codeAria: "code for clean tablet project",
  },
  {
    title: "portfolio",
    live: None,
    code: "https://github.com/jamessouth/portfolio",
    path: "bg-port",
    text: "I just updated my portfolio site to move from ReasonML to ReScript, which branched off of Reason to focus on web right as I was first making this. Reason was my introduction to OCaml, which I really like.",
    liveAria: "",
    codeAria: "code for portfolio project",
  },
  {
    title: "dashboard",
    live: Some("https://jamessouth.github.io/dashboard/"),
    code: "https://github.com/jamessouth/dashboard",
    path: "bg-dash",
    text: "Dashboard was originally a plain JavaScript bootcamp project that I rebuilt with Vue, Vuex, Vue Router, and real data from the World Bank and NASA. I wanted to learn about Progressive Web Apps, so I added a service worker, manifest, icon, and necessary UI changes and it is now an installable PWA!",
    liveAria: "live site for web app dashboard project",
    codeAria: "code for web app dashboard project",
  },
  {
    title: "directory",
    live: Some("https://jamessouth.github.io/directory/"),
    code: "https://github.com/jamessouth/directory",
    path: "bg-dir",
    text: "Directory was also a plain JavaScript project from the bootcamp I went to. I rebuilt it with React and also made it into a PWA. I added a sort feature on top of the original filter requirement and I worked a lot on accessibility, including adding ARIA roles and testing with a screen reader (NVDA).",
    liveAria: "live site for employee directory project",
    codeAria: "code for employee directory project",
  },
  {
    title: "15 puzzle generator",
    live: Some("https://jamessouth.github.io/fifteen-puzzle-generator/home"),
    code: "https://github.com/jamessouth/fifteen-puzzle-generator",
    path: "bg-puzz",
    text: "15 Puzzle Generator was the first idea of my own that I developed. I originally built it to learn Vue but have since rebuilt it with Angular and TypeScript. It has routing and animated page transitions and I used RxJS for communication among components. I styled it with a mix of Art Deco fonts and Art Nouveau artwork from Czech artist Alfons Mucha. Check out the live puzzle demo!",
    liveAria: "live site for 15 puzzle generator project",
    codeAria: "code for 15 puzzle generator project",
  },
  {
    title: "face scramble!",
    live: None,
    code: "https://github.com/jamessouth/face-scramble",
    path: "bg-face",
    text: "In 2018, I attended a conference where I learned about programming for mobile devices with NativeScript. I had already devised code to play a 15 puzzle for my first portfolio site and my 15 Puzzle Generator project, so I immediately had an idea for what to build with NativeScript. Face Scramble! was also my first foray into Angular and TypeScript. Unfortunately, my computer isn't powerful enough to build this for mobile, so for now, on the GitHub repo, I just have a GIF of me playing it on my old Android phone.",
    liveAria: "",
    codeAria: "code for face scramble project",
  },
  {
    title: "polybar modules",
    live: None,
    code: "https://github.com/jamessouth?tab=repositories&q=polybar",
    path: "bg-poly",
    text: "",
    liveAria: "",
    codeAria: "list of polybar projects",
  },
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
