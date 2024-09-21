let data = [20, 49, 50, 51, 52, 36];
let postion = 3;
for (let i = postion; i <= data.length - 1; i++) {
    data[i] = data[i + 1];
}               
data.length = data.length - 1
console.warn(data);