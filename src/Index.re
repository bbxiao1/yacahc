
List.iter(((filepath, color, id)) => {
  let _ = Js.Promise.(
    Fetch.fetch(filepath)
    |> then_(Fetch.Response.text)
    |> then_((text) => {
      resolve(Js.String.split("\n", text));
    })
  )
  |> Js.Promise.then_(texts => {
      ReactDOMRe.renderToElementWithId(<CardList allText=texts color=color />, id)
    } |> Js.Promise.resolve)
}, [("/assets/black.txt", Card.Black, "black"), ("/assets/white.txt", Card.White, "white")])
