[@react.component]
let make = () => { //caba99
    <header className="fixed bg-yellow-crayola top-0 w-full h-24 z-20 exp:h-12">
        <nav className="my-0 mx-2 h-full">
            <ul className="font-corm flex flex-row justify-around items-center flex-wrap h-full">
                <li>
                    <a href="#about">"About"->React.string</a>
                </li>
                <li>
                    <a href="#port">"Port"->React.string</a>
                </li>
                <li>
                    <a href="#articles">"Articles"->React.string</a>
                </li>
                <li>
                    <a href="#cont">"Contact"->React.string</a>
                </li>
                <li>
                    <a className="newwindow" target="_blank" rel="noopener noreferrer" >{js|Résumé|js}->React.string</a>
                </li>
            </ul>
        </nav>
    </header>
};




// https://coolors.co/d00000-bdc667-77966d-626d58-413c58