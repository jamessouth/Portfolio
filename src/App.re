let paths = Js.Dict.fromArray([|
    ("about", "./src/assets/wdksmall.png"),
    ("articles", "./src/assets/arts.jpg"),
    ("contact", "./src/assets/contsprite.png"),
    ("footPic", "./src/assets/icons.png"),
    ("footRes", "./src/assets/resume.pdf"),
|]);

let navLinks = [|
  ("JS", "#about", "", "", "", "JS"),
  ("portfolio icon", "#port", "", "", "", "P"),
  ("articles icon", "#articles", "", "", "", "A"),
  ("contact icon", "#cont", "", "", "", "C"),
|];

let file = (dict, key) => dict->Js.Dict.unsafeGet(key);
let filePath = file(paths);

[@react.component]
let make = () => {
    <>
        <main>
            <About
                path=filePath("about")
            />
            <Port/>
            <Articles
                path=filePath("articles")
            />
            <Contact
                path=filePath("contact")
            />
        </main>
        <Footer
            picPath=filePath("footPic")
            resPath=filePath("footRes")
            navLinks
        />
    </>
};