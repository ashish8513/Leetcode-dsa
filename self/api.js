async function quotes() {
    try {

        const response = await fetch('https://type.fit/api/quotes')
        const data = await response.json()
        console.log(data);
    } catch (err) {
        console.log('Error fetching data', err);
    } finally {
        console.log("api closed in the data ");
    }
}
quotes();