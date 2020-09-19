[@react.component]
let make = () => {
    <header className="fixed top-0 w-full h-24 bg-pale-spring-bud z-20 exp:h-12">
        <nav>
            <ul className="font-corm">
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
                    <a target="_blank" rel="noopener noreferrer" >{js|Résumé|js}->React.string</a>
                </li>
            </ul>
        </nav>
    </header>
};
// https://coolors.co/d00000-381d2a-3e6990-aabd8c-e9e3b4