// Given an array of integers, return the length of the longest consecutive sequence of numbers.

//revers number 

function reverseNumber(str) {
    const rev = str.toString().split('').reverse().join('')
    return Number(rev)
}

console.log("level", reverseNumber(1234));


//reverse string

function isPlaindrom(str) {
    const rev = str.split('').reverse().join('')
    return str === rev;
}

console.log("level", isPlaindrom("level"));


// Find max & min in an array
// method 1 approach 
// function findMaxMin(arr) {
//     const max = Math.max(...arr);
//     return max;
// }

// console.log("Max:", findMaxMin([1, 2, 3, 4, 5]));

// method 2 approach
function FindMaxandMin(arr) {
    let max = arr[0];
    for (let i = 1; i < arr.length; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
console.log("Max:", FindMaxandMin([1, 2, 3, 4, 9]));


// count Vowels in a string 

function countVowels(str) {
    const vowels="aeiou";
    let count =0;
    for (let i = 0; i < str.length; i++) {
        if (vowels.includes(str[i].toLowerCase())) {
            count++;
        }
    }
    return count;
}

console.log("Count of Vowels:", countVowels("Ashish Prabhakar"));   