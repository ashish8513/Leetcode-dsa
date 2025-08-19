/**
 * @param {number[]} nums
 * @return {number}
 */
var zeroFilledSubarray = function(nums) {
    let tot = 0;
    let curr = 0;
    for(let i=0;i<nums.length;i++){
        if(nums[i]==0){
                curr++;
                tot +=curr;            
        }else{
                curr = 0;
        }
    }

    return tot;
};