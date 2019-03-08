Loader.load()
|> Js.Promise.then_(firstCard => ReactDOMRe.renderToElementWithId(<Component1 message=firstCard />, "index1") |> Js.Promise.resolve);

ReactDOMRe.renderToElementWithId(<Component2 greeting="Hello!" />, "index2");
