[@react.component]
let make = (~path) => {
    let picState = Hook.useFetch(true, path);

    <section className="flex flex-row-reverse portrait:flex-col min-h-screen" id="about">
        <div className="bg-img-bg portrait:h-half-screen wdk1:h-auto w-1/2 portrait:w-auto">
            <img
                src={switch (picState) {
                      | Error(_)
                      | LoadingImg => ""
                      | LoadedImg(src) => src
                }}
                className="h-full object-cover object-left w-full"
                alt="a web dev's desk and laptop"
            />
        </div>
        <div className="w-1/2 portrait:w-auto">
            <h1
                className="my-20 font-bold font-corm text-center text-4xl md:text-5xl lg:text-6xl"
            >
                "James South"->React.string
            </h1>
            <p
                className="font-gara text-2xl mx-auto mb-20 w-4/5 lg:text-3xl"
            >
                "I am a self-taught developer and bootcamp grad and I'm changing careers to become a full-stack engineer! Please scroll down to see my portfolio or go straight to "->React.string<a rel="noopener noreferrer" href="https://github.com/jamessouth">"my GitHub overview"->React.string</a>". Before learning to code, I passed the "->React.string<a rel="noopener noreferrer" href="https://www.cfainstitute.org/en/programs/cfa/exam">"CFA exam"->React.string</a>"! I mentor the Go track at "->React.string<a rel="noopener noreferrer" href="https://exercism.io/tracks/go/mentors">"Exercism.io"->React.string</a>" and I am also a Go Concept Exercise contributor for "->React.string<a rel="noopener noreferrer" href="https://exercism.github.io/v3/#/">"Exercism v3"->React.string</a>"."->React.string
            </p>
        </div>
    </section>
};