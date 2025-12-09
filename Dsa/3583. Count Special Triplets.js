// You are given an integer array nums.

// A special triplet is defined as a triplet of indices (i, j, k) such that:

// 0 <= i < j < k < n, where n = nums.length
// nums[i] == nums[j] * 2
// nums[k] == nums[j] * 2
// Return the total number of special triplets in the array.

// Since the answer may be large, return it modulo 109 + 7.


var specialTriplets = function(nums) {
    const MOD = 1_000_000_007;
    const n = nums.length;

    let leftFreq = new Map();
    let rightFreq = new Map();

   
    for (let num of nums) {
        rightFreq.set(num, (rightFreq.get(num) || 0) + 1);
    }

    let result = 0;

    for (let j = 0; j < n; j++) {
        let x = nums[j];

      
        rightFreq.set(x, rightFreq.get(x) - 1);

        let target = 2 * x;

        let leftCount = leftFreq.get(target) || 0;      
        let rightCount = rightFreq.get(target) || 0;   

        result = (result + leftCount * rightCount) % MOD;

        
        leftFreq.set(x, (leftFreq.get(x) || 0) + 1);
    }

    return result;
};
