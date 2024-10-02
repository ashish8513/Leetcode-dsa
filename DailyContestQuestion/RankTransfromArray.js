// Given an array of integers arr, replace each element with its rank.

// The rank represents how large the element is. The rank has the following rules:

// Rank is an integer starting from 1.
// The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
// Rank should be as small as possible.

function arrayRankTransform(arr) {
    if (arr.length === 0) return [];
  
    let sortedArr = [...arr].sort((a, b) => a - b);
    
    let rankMap = new Map();
    let rank = 1;
  
    for (let i = 0; i < sortedArr.length; i++) {
      if (!rankMap.has(sortedArr[i])) {
        rankMap.set(sortedArr[i], rank);
        rank++;
      }
    }
  
    return arr.map(num => rankMap.get(num));
  }
  
  let arr = [40, 10, 20, 30];
  console.log(arrayRankTransform(arr)); // Output: [4, 1, 2, 3]
  