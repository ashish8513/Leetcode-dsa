/**Given a positive integer millis, write an asynchronous function that sleeps for millis milliseconds. It can resolve any value.*/
async function sleep(millis) {
    return new Promise(resolve => {
        setTimeout(resolve(200), millis)
    });
}
 
sleep(200).then(result => console.log(result));