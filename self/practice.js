function fibonicc(n) {
    let series = [];
    let a = 0, b = 1;
    for (let i = 0; i < n; i++) {
        series.push(a)
        let next = a + b;
        a = b;
        b = next
    }
    return series;
}
let num = 10;
console.log(fibonicc(num))