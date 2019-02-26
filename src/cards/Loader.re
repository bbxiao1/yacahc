let load = () => {
    Js.Promise.(
        Fetch.fetch("./black.txt")
        |> then_(Fetch.Response.text)
        |> then_((text) => {
            resolve(text);
            // resolve(Array.get(Js.String.split("\n", text), 0));
        })
    );
}
