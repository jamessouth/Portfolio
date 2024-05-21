@react.component
let make = () => {
  // let picState = Hook.useFetch(true, path);~path

  <section className="flex flex-row-reverse  min-h-screen" id="about">
    <div className="bg-zinc-100 wdk1:h-auto w-1/2 ">
      <img
        src={switch picState {
        | Error(_)
        | LoadingImg => ""
        | LoadedImg(src) => src
        }}
        className="h-full object-cover object-left w-full"
        alt="a web dev's desk and laptop"
      />
    </div>
    <div className="w-1/2 ">
      <h1 className="my-20 font-bold font-corm text-center text-4xl md:text-5xl lg:text-6xl">
        React.string
        "James South"
      </h1>
      <p className="font-gara text-2xl mx-auto mb-20 w-4/5 lg:text-3xl">
        React.string
        "I am a self-taught developer and bootcamp grad and I'm changing careers to become a full-stack engineer! Please scroll down to see my portfolio or go straight to "
        <a rel="noopener noreferrer" href="https://github.com/jamessouth">
          React.string
          "my GitHub overview"
        </a>
        React.string
        ". Before learning to code, I passed the "
        <a rel="noopener noreferrer" href="https://www.cfainstitute.org/en/programs/cfa/exam">
          React.string
          "CFA exam"
        </a>
        React.string
        "! I mentor the Go track at "
        <a rel="noopener noreferrer" href="https://exercism.io/tracks/go/mentors">
          React.string
          "Exercism.io"
        </a>
        React.string
        " and I am also a Go Concept Exercise contributor for "
        <a rel="noopener noreferrer" href="https://exercism.github.io/v3/#/">
          React.string
          "Exercism v3"
        </a>
        React.string
        "."
      </p>
    </div>
  </section>
}
