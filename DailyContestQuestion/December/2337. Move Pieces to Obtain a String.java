// You are given two strings start and target, both of length n. Each string consists only of the characters 'L', 'R', and '_' where:

// The characters 'L' and 'R' represent pieces, where a piece 'L' can move to the left only if there is a blank space directly to its left, and a piece 'R' can move to the right only if there is a blank space directly to its right.
// The character '_' represents a blank space that can be occupied by any of the 'L' or 'R' pieces.
// Return true if it is possible to obtain the string target by moving the pieces of the string start any number of times. Otherwise, return false.

 /**
 * @param {string} start
 * @param {string} target
 * @return {boolean}
 */
var canChange = function (start, target) {
    let x = 0, y = 0;

    while (x < start.length || y < target.length) {
        while (x < start.length && start[x] === '_') {
            x++;
        }
        while (y < target.length && target[y] === '_') {
            y++;
        }
        if (start[x] !== target[y]) return false;

        if (start[x] === 'L' && x < y) return false;

        if (start[x] === 'R' && y < x) return false;

        x++;
        y++;
    }
    return true;
};