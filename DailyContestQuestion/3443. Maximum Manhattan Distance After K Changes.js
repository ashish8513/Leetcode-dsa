// You are given a string s consisting of the characters 'N', 'S', 'E', and 'W', where s[i] indicates movements in an infinite grid:

// 'N' : Move north by 1 unit.
// 'S' : Move south by 1 unit.
// 'E' : Move east by 1 unit.
// 'W' : Move west by 1 unit.
// Initially, you are at the origin (0, 0). You can change at most k characters to any of the four directions.

// Find the maximum Manhattan distance from the origin that can be achieved at any time while performing the movements in order.

// The Manhattan Distance between two cells (xi, yi) and (xj, yj) is |xi - xj| + |yi - yj|.


/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var maxDistance = function(s, k) {
    let ans = 0;

    // Direction counters: to keep cumulative counts of each type of move.
    let north = 0;
    let south = 0;
    let east = 0;
    let west = 0;

    let n = s.length;

    for (let i = 0; i < n; i++) {
        // Movement direction tracking
        if (s[i] == 'N') north++;
        else if (s[i] == 'S') south++;
        else if (s[i] == 'E') east++;
        else if (s[i] == 'W') west++;

     
        let x = Math.abs(east - west);
        let y = Math.abs(north - south);
        let distance = x + y;

       
        let gain = distance + Math.min(2 * k, i + 1 - distance);

        ans = Math.max(ans, gain);
    }

    return ans;
};