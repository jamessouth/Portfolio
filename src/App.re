let paths = Js.Dict.fromArray([|
    ("about", "./src/assets/wdksmall.png"),
    ("footPic", "./src/assets/icons.png"),
    ("footRes", "./src/assets/resume.pdf"),
|]);



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
            <Articles/>
            <Contact/>
        </main>
        <Footer
            picPath=filePath("footPic")
            resPath=filePath("footRes")
        />
    </>
};