@react.component
let make = () => {
  // let picState = Hook.useFetch(true, path);~path

  <section className="flex flex-col" id="about">
    <div className="bg-contain bg-no-repeat bg-top h-64 bg-about mw448:bg-auto" />
    <div className="">
      <h1
        className="mb-10 mw368:mt-5 mw400:mt-10 mw448:mt-16 font-bold font-corm text-center text-4xl md:text-5xl lg:text-6xl">
        {"James South"->React.string}
      </h1>
      <p
        className="font-gara text-2xl mx-auto mb-20 w-4/5 lg:text-3xl/10 first-letter:text-7xl lg:first-letter:text-8xl first-letter:text-orange
  first-letter:mr-2.5 first-letter:ml-2.5 first-letter:mt-2.5 first-letter:float-left">
        {"I am a self-taught developer and bootcamp grad and I'm changing careers to become a full-stack engineer! Please scroll down to see my portfolio or go straight to "->React.string}
        <a rel="noopener noreferrer" href="https://github.com/jamessouth">
          {"my GitHub overview"->React.string}
        </a>
        {". Before learning to code, I passed the "->React.string}
        <a rel="noopener noreferrer" href="https://www.cfainstitute.org/en/programs/cfa/exam">
          {"CFA exam"->React.string}
        </a>
        {"! I mentor the Go track at "->React.string}
        <a rel="noopener noreferrer" href="https://exercism.io/tracks/go/mentors">
          {"Exercism.io"->React.string}
        </a>
        {" and I am also a Go Concept Exercise contributor for "->React.string}
        <a rel="noopener noreferrer" href="https://exercism.github.io/v3/#/">
          {"Exercism v3"->React.string}
        </a>
        {"."->React.string}
      </p>
    </div>
  </section>
}
