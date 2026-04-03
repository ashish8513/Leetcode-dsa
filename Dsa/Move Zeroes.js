function pushZerosToEnd(arr)
{
    const n = arr.length;
    const temp = new Array(n);

    let j = 0;

    for (let i = 0; i < n; i++) {
        if (arr[i] !== 0) {
            temp[j++] = arr[i];
        }
    }

    while (j < n)
        temp[j++] = 0;

    for (let i = 0; i < n; i++)
        arr[i] = temp[i];
}

const arr = [ 1, 2, 0, 4, 3, 0, 5, 0 ];
pushZerosToEnd(arr);

console.log(arr.join(" "));
