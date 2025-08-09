// Given an array of integers, return the length of the longest consecutive sequence of numbers.

//revers number 

function reverseNumber(str) {
    const rev = str.toString().split('').reverse().join('')
    return Number(rev)
}

console.log("level", reverseNumber(1234));


//reverse string

function isPlaindrom(str){
    const rev=str.split('').reverse().join('')
    return str === rev;
}

console.log("level", isPlaindrom("level"));

