
function mergedArry(arr1, arr2) {

    const mergedArry = arr2.concat(arr1)
    mergedArry.sort((a, b) => a - b)
    return mergedArry
}
const arr1 = [1, 2, 4]
const arr2 = [1, 3, 4]
const output = (mergedArry(arr1, arr2))
console.log(output)
