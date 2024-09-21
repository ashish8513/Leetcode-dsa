function CalculateNumberoflength(str) {
    let length = 0;
    while (str[length] !== undefined) {
        length++
    }
    return length;
}
let strExample = "Ashishprabhakar"
console.log(CalculateNumberoflength(strExample))