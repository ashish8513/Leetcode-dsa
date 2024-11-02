// You are given a 2D integer array intervals where intervals[i] = [lefti, righti] represents the inclusive interval [lefti, righti].

// You have to divide the intervals into one or more groups such that each interval is in exactly one group, and no two intervals that are in the same group intersect each other.

// Return the minimum number of groups you need to make.

// Two intervals intersect if there is at least one common number between them. For example, the intervals [1, 5] and [5, 8] intersect.


/**
 * @param {number[][]} intervals
 * @return {number}
 */
var minGroups = function (intervals) {
    if (intervals.length === 0) return 0;
  
    let rooms = 0
    let e = 0
  
    const startTimes = intervals.map((interval) => interval[0]).sort((a, b) => a - b)
    const endTimes = intervals.map((interval) => interval[1]).sort((a, b) => a - b)
  
    for (let i = 0; i < intervals.length; i++) {
      if (startTimes[i] <= endTimes[e]) rooms++
      else e++
    }
    return rooms
  };