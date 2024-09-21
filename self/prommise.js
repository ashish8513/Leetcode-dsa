let newPromise = new Promise((resolve, reject) => {
    let randomNumber = Math.random()
    console.log(randomNumber);
    if (randomNumber > 0.5) {
        resolve("Success")
    } else {
        reject("Failure")
    }
})
newPromise.then((result) => console.log("result bb", result))   