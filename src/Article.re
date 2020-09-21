[@react.component]
let make = (~link, ~title, ~aid) => {

    <div>
        <a rel="noopener noreferrer" href=link>title->React.string</a>
        <div className="w-40 h-40" id=aid>


        </div>
    </div>
};