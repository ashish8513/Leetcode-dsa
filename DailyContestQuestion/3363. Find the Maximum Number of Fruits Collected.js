// There is a game dungeon comprised of n x n rooms arranged in a grid.

// You are given a 2D array fruits of size n x n, where fruits[i][j] represents the number of fruits in the room (i, j). Three children will play in the game dungeon, with initial positions at the corner rooms (0, 0), (0, n - 1), and (n - 1, 0).

// The children will make exactly n - 1 moves according to the following rules to reach the room (n - 1, n - 1):

// The child starting from (0, 0) must move from their current room (i, j) to one of the rooms (i + 1, j + 1), (i + 1, j), and (i, j + 1) if the target room exists.
// The child starting from (0, n - 1) must move from their current room (i, j) to one of the rooms (i + 1, j - 1), (i + 1, j), and (i + 1, j + 1) if the target room exists.
// The child starting from (n - 1, 0) must move from their current room (i, j) to one of the rooms (i - 1, j + 1), (i, j + 1), and (i + 1, j + 1) if the target room exists.
// When a child enters a room, they will collect all the fruits there. If two or more children enter the same room, only one child will collect the fruits, and the room will be emptied after they leave.

// Return the maximum number of fruits the children can collect from the dungeon.



var maxCollectedFruits = function (fruits) {
    const n = fruits.length;
    let ans = 0;
    for (let i = 0; i < n; ++i) ans += fruits[i][i];

    function dp() {
        let prev = Array(n).fill(-Infinity);
        let curr = Array(n).fill(-Infinity);
        prev[n - 1] = fruits[0][n - 1];

        for (let i = 1; i < n - 1; ++i) {
            for (let j = Math.max(n - 1 - i, i + 1); j < n; ++j) {
                let best = prev[j];
                if (j - 1 >= 0) {
                    best = Math.max(best, prev[j - 1]);
                }
                if (j + 1 < n) {
                    best = Math.max(best, prev[j + 1]);
                }
                curr[j] = best + fruits[i][j];
            }
            [prev, curr] = [curr, prev];
        }
        return prev[n - 1];
    }

    ans += dp();
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < i; ++j) {
            [fruits[i][j], fruits[j][i]] = [fruits[j][i], fruits[i][j]];
        }
    }

    ans += dp();
    return ans;
};