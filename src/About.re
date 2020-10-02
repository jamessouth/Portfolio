[@react.component]
let make = () => {
    <section className="flex flex-row-reverse portrait:flex-col min-h-screen" id="about">
        <div className="bg-img-bg h-half-screen wdk1:h-auto w-1/2 portrait:w-auto">
            <img
                className="h-full object-cover object-left w-full"
                alt="a web dev's desk and laptop"
                src="./src/assets/wdksmall.png"
            />
        </div>
        <div className="w-1/2 portrait:w-auto">
            <h1 className="my-20 font-bold font-corm text-center text-4xl md:text-5xl lg:text-6xl lg:m-56">"James South"->React.string</h1>
            // <h2>"About Me"->React.string</h2>
            <p className="font-gara text-2xl mx-auto mb-20 w-4/5 lg:text-3xl max-w-harp">"I am a self-taught developer and bootcamp grad and I'm changing careers to become a full-stack engineer! Please scroll down to see my portfolio or go straight to "->React.string<a rel="noopener noreferrer" href="https://github.com/jamessouth">"my GitHub overview"->React.string</a>". Before learning to code, I passed the "->React.string<a rel="noopener noreferrer" href="https://www.cfainstitute.org/en/programs/cfa/exam">"CFA exam"->React.string</a>"! I mentor the Go track at "->React.string<a rel="noopener noreferrer" href="https://exercism.io/tracks/go/mentors">"Exercism.io"->React.string</a>" and I am also a Go Concept Exercise contributor for "->React.string<a rel="noopener noreferrer" href="https://exercism.github.io/v3/#/">"Exercism v3"->React.string</a>"."->React.string
            // <time dateTime="2009-05">"May 2009"->React.string</time><cite>" Harper's Magazine"->React.string</cite><a rel="noopener noreferrer" href="https://en.wikipedia.org/wiki/Cryptic_crossword">" cryptic crossword"->React.string</a>" puzzle contest World Champion "->React.string<span>{js|😉|js}->React.string</span>":"->React.string
            </p>
        </div>

        // <p className="mt-10 mb-1 text-lg font-sans mx-auto w-11/12 max-w-harp">"From the "->React.string<time dateTime="2009-07">"July 2009"->React.string</time>" issue of "->React.string<cite>"Harper's Magazine:"->React.string</cite></p>
        // <div className="overflow-x-scroll lg:overflow-x-auto w-11/12 mx-auto max-w-harp">
        //     <img
        //         className="max-w-none"
        //         alt="clipping from Harper's Magazine showing James South as a puzzle contest winner"
        //         src="./src/assets/harpers.jpg"
        //     />
        // </div>
    </section>
};
