// 2491. Divide Players Into Teams of Equal Skill
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given a positive integer array skill of even length n where skill[i] denotes the skill of the ith player. Divide the players into n / 2 teams of size 2 such that the total skill of each team is equal.

// The chemistry of a team is equal to the product of the skills of the players on that team.

// Return the sum of the chemistry of all the teams, or return -1 if there is no way to divide the players into teams such that the total skill of each team is equal.

var dividePlayers = function (skill) {
    const n = skill.length,
        m = n / 2;
    skill.sort((a, b) => a - b);
    const sum = skill[0] + skill[n - 1];
    let ans = 0;
    for (let i = 0; i < m; i++) {
        const x = skill[i],
            y = skill[n - 1 - i];
        if (x + y != sum) return -1;
        ans += x * y;
    }
    return ans;
};