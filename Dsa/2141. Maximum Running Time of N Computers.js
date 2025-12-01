// You have n computers. You are given the integer n and a 0-indexed integer array batteries where the ith battery can run a computer for batteries[i] minutes. You are interested in running all n computers simultaneously using the given batteries.

// Initially, you can insert at most one battery into each computer. After that and at any integer time moment, you can remove a battery from a computer and insert another battery any number of times. The inserted battery can be a totally new battery or a battery from another computer. You may assume that the removing and inserting processes take no time.

// Note that the batteries cannot be recharged.

// Return the maximum number of minutes you can run all the n computers simultaneously.

/**
 * @param {number} n
 * @param {number[]} batteries
 * @return {number}
 */

function maxRunTime(n, batteries) {
    let total = batteries.reduce((acc, x) => acc + x, 0)
    let batts = batteries.sort((a, b) => b - a)
    let i = 0
    while (1) {
        let average_truncated = parseInt(total / n)
        let cur = batts[i]
        if (cur > average_truncated) {
            total -= cur
            n--
            i++
        } else {
            return average_truncated
        }
    }
};
