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
        className="font-gara text-2xl mx-auto mb-20 w-5/6 lg:text-3xl/10 first-letter:text-7xl lg:first-letter:text-8xl first-letter:text-orange
  first-letter:mr-2.5 first-letter:ml-2.5 first-letter:mt-2.5 first-letter:float-left">
        {"I am a computer science and math student at "->React.string}
        <a
          rel="noopener noreferrer"
          href="https://www.hsutx.edu/academics/undergraduate-majors-minors/computer-science-degrees/">
          {"Hardin-Simmons University"->React.string}
        </a>
        {" in Abilene, Texas. I have a 4.0 GPA and will graduate in 2025 with a BSc. I previously earned a BA in accounting from Southwestern University in Georgetown, Texas, and I have also passed the "->React.string}
        <a rel="noopener noreferrer" href="https://www.cfainstitute.org/en/programs/cfa/exam">
          {"CFA exam"->React.string}
        </a>
        {". I used to mentor the Go track at "->React.string}
        <a rel="noopener noreferrer" href="https://exercism.io/tracks/go/mentors">
          {"Exercism.io"->React.string}
        </a>
        {" and I also wrote three Go Concept Exercises for them. I have been a "->React.string}
        <a rel="noopener noreferrer" href="https://archlinux.org/"> {"Linux"->React.string} </a>
        {" user for three years. For school we use private Bitbucket repos, but here I want to show some of my personal projects from "->React.string}
        <a rel="noopener noreferrer" href="https://github.com/jamessouth">
          {"my GitHub account"->React.string}
        </a>
        {"."->React.string}
      </p>
    </div>
  </section>
}
