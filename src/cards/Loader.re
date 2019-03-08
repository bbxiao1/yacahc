let load = () => {
    Js.Promise.(
        Fetch.fetch("/assets/black.txt")
        |> then_(Fetch.Response.text)
        |> then_((text) => {
            resolve(Array.get(Js.String.split("\n", text), 0));
        })
    );
}
