    // // Traverse the array from right to left and try to form ramps
    // A ramp in an integer array nums is a pair (i, j) for which i < j and nums[i] <= nums[j]. The width of such a ramp is j - i.

    // Given an integer array nums, return the maximum width of a ramp in nums. If there is no ramp in nums, return 0.
    
     /**
 * @param {number[]} nums
 * @return {number}
 */
function maxWidthRamp(nums) {
    const n = nums.length;
    const stk = [];
    
    // Build the stack of indices where nums[stk[i]] is in descending order
    for (let i = 0; i < n; ++i) {
        if (stk.length === 0 || nums[stk[stk.length - 1]] > nums[i]) {
            stk.push(i);
        }
    }
    
    let maxWidth = 0;
    
    for (let i = n - 1; i >= 0; --i) {
        while (stk.length > 0 && nums[stk[stk.length - 1]] <= nums[i]) {
            maxWidth = Math.max(maxWidth, i - stk.pop());
        }
    }
    
    return maxWidth;
}
