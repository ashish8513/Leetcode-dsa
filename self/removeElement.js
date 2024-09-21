function removeElement(num, val) {
    let k=0;
    for (let i=0; i<num.length; i++) {
        if(num[i] !== val){
            num[k] = num[i];
            k++;
        }
    }
    return k;
}
let num = [3, 2, 2, 3];
let val = 3;
let k = removeElement(num, val)
console.log(k)
console.error(num)