// You are given a 2D integer array intervals where intervals[i] = [starti, endi] represents all the integers from starti to endi inclusively.

// A containing set is an array nums where each interval from intervals has at least two integers in nums.

// For example, if intervals = [[1,3], [3,7], [8,9]], then [1,2,4,7,8,9] and [2,3,4,8,9] are containing sets.
// Return the minimum possible size of a containing set.


/**
 * @param {number[][]} intervals
 * @return {number}
 */

var intersectionSizeTwo = function(intervals) {

    // we sort by end ascending; if ends are equal, we sort by start descending
    intervals.sort((a, b) => {
        if (a[1] === b[1]) return b[0] - a[0];
        return a[1] - b[1];
    });

    let nums = 0;
    let a = -1, b = -1; // last two selected elements

    for (let [start, end] of intervals) {

        // we count how many of a, b are in the current interval
        let count = 0;
        if (a >= start) count++;
        if (b >= start) count++;

        if (count >= 2) continue;

        if (count === 1) {
            nums++;
            a = b;
            b = end;
        } else {
            nums += 2;
            a = end - 1;
            b = end;
        }
    }

    return nums;
};
