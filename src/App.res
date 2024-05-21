// let file = (dict, key) => dict->Js.Dict.unsafeGet(key)
// let filePath = file(Data.paths)

@react.component
let make = () => {
  <>
    // <Footer picPath={filePath("footPic")} resPath={filePath("footRes")} navLinks=Data.navLinks />
    <main>
      //   <About path={filePath("about")} />
      <Project
        title="james south"
        live=None
        code=""
        text="hi"
        liveAria=""
        codeAria=""
        i=1
        key="james south"
        path="bg-about"
      />
      <Port projects=Data.projects />
      //   <Articles path={filePath("articles")} id="articles" />
      //   <Contact links=Data.links path={filePath("contact")} id="cont" />
    </main>
  </>
}
