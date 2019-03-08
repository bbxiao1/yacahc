
List.iter(((filepath, id)) => {
  let _ = Js.Promise.(
    Fetch.fetch(filepath)
    |> then_(Fetch.Response.text)
    |> then_((text) => {
      resolve(Js.String.split("\n", text));
    })
  )
  |> Js.Promise.then_(texts => {
      Random.init(int_of_float(Js.Date.now()));

      let shuffled = texts;
      let l = Array.length(texts);
      for (i in (l-1) downto 0) {
        let r = Random.int(i+1);
        Js.log(Js.Int.toString(r));
        let tmp = shuffled[i];
        shuffled[i] = shuffled[r];
        shuffled[r] = tmp;
      }
      switch (id) {
      | "blackstack" => ReactDOMRe.renderToElementWithId(<BlackCardStack shuffled=shuffled />, id);
      | _ => ReactDOMRe.renderToElementWithId(<WhiteCardStack shuffled=shuffled />, id);
      }
    } |> Js.Promise.resolve)
}, [("/assets/black.txt", "blackstack"), ("/assets/white.txt", "whitestack")]);
