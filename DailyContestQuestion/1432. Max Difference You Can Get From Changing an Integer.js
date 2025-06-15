// 1432. Max Difference You Can Get From Changing an Integer

// You are given an integer num. You will apply the following steps to num two separate times:

// Pick a digit x (0 <= x <= 9).
// Pick another digit y (0 <= y <= 9). Note y can be equal to x.
// Replace all the occurrences of x in the decimal representation of num by y.
// Let a and b be the two results from applying the operation to num independently.

// Return the max difference between a and b.

// Note that neither a nor b may have any leading zeros, and must not be 0.

 /**
 * @param {number} num
 * @return {number}
 */
var maxDiff = function(num) {
 const numStr = num.toString();
    const uniqueDigits = new Set(numStr.split(''));
    let maxVal = num;
    let minVal = num;

    for (const digit of uniqueDigits) {
      for (let newDigit = 0; newDigit <= 9; newDigit++) {
        if (digit === numStr[0] && newDigit === 0) continue;
        const newNumStr = numStr.split(digit).join(newDigit.toString());
        const newNum = parseInt(newNumStr, 10);
        maxVal = Math.max(maxVal, newNum);
        minVal = Math.min(minVal, newNum); 
         }
    }

    return maxVal - minVal;
  
};