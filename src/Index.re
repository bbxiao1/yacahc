type cards = {
  black: list(string),
  white: list(string),
}

let promises = Array.map((filepath) => {
  Js.Promise.(
    Fetch.fetch(filepath)
    |> then_(Fetch.Response.text)
    |> then_((text) => {
      resolve(Js.String.split("\n", text));
    })
    |> then_((texts) => {
      Random.init(int_of_float(Js.Date.now()));

      let shuffled = texts;
      let l = Array.length(texts);
      for (i in (l-1) downto 0) {
        let r = Random.int(i+1);
        let tmp = shuffled[i];
        shuffled[i] = shuffled[r];
        shuffled[r] = tmp;
      }
      let cards = shuffled;
      resolve(cards);
    })
  )
}, [|"/assets/black.txt", "/assets/white.txt"|]);
Js.Promise.(
  all(promises)
  |> then_((cards) => {
    let lCards = Array.map((stack) => {
      Array.to_list(stack)
    }, cards);
    // resolved cards array is supposed to be ordered
    ReactDOMRe.renderToElementWithId(<Coordinator blackCards=lCards[0] whiteCards=lCards[1] />, "coordinator")
  } |> resolve)
)
