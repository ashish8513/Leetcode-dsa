// You are given two integer arrays, skill and mana, of length n and m, respectively.

// In a laboratory, n wizards must brew m potions in order. Each potion has a mana capacity mana[j] and must pass through all the wizards sequentially to be brewed properly. The time taken by the ith wizard on the jth potion is timeij = skill[i] * mana[j].

// Since the brewing process is delicate, a potion must be passed to the next wizard immediately after the current wizard completes their work. This means the timing must be synchronized so that each wizard begins working on a potion exactly when it arrives. ​

// Return the minimum amount of time required for the potions to be brewed properly.


/**
 * @param {number[]} skill
 * @param {number[]} mana
 * @return {number}
 */
var minTime = function(skill, mana) {
    
    const n = skill.length;
    const freeTime = new Array(n).fill(0);

    for (let x of mana) {
        let now = freeTime[0];

        // forward pass: we simulate potion brewing
        for (let i = 1; i < n; i++) {
            const brew = skill[i - 1] * x;
            now = Math.max(now + brew, freeTime[i]);
        }
        freeTime[n - 1] = now + skill[n - 1] * x;

        // reverse pass: we update free times for next potion
        for (let i = n - 2; i >= 0; i--) {
            freeTime[i] = freeTime[i + 1] - skill[i + 1] * x;
        }
    }

    return freeTime[n - 1];
};
// 