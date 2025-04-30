// Given an array nums of integers, return how many of them contain an even number of digits

/**
 * @param {number[]} nums
 * @return {number}
 */
var findNumbers = function (nums) {
    return nums.filter(num => num.toString().length % 2 === 0).length;
};