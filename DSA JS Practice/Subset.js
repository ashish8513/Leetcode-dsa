// Given an integer array nums that may contain duplicates, return all possible 
// subsets
//  (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

function subsetsWithDup(nums) {
    // Sort the array to handle duplicates
    nums.sort((a, b) => a - b);
    
    const result = [];
    
    // Helper function for backtracking
    const backtrack = (start, currentSubset) => {
        // Push a copy of the current subset to the result
        result.push([...currentSubset]);
        
        // Iterate over the remaining elements
        for (let i = start; i < nums.length; i++) {
            // If the current element is the same as the previous, skip it to avoid duplicates
            if (i > start && nums[i] === nums[i - 1]) continue;
            
            // Include the current element in the subset
            currentSubset.push(nums[i]);
            
            // Recurse with the updated subset and move the start to the next element
            backtrack(i + 1, currentSubset);
            
            // Backtrack by removing the last element from the current subset
            currentSubset.pop();
        }
    };
    
    // Start the backtracking process with an empty subset
    backtrack(0, []);
    
    return result;
}

// Example usage:
const nums = [1, 2, 2];
console.log(subsetsWithDup(nums));
