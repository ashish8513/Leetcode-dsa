// There are n dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some of the dominoes either to the left or to the right.

// After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.

// When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.

// For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.

// You are given a string dominoes representing the initial state where:

// dominoes[i] = 'L', if the ith domino has been pushed to the left,
// dominoes[i] = 'R', if the ith domino has been pushed to the right, and
// dominoes[i] = '.', if the ith domino has not been pushed.
// Return a string representing the final state.


/**
 * @param {string} dominoes
 * @return {string}
 */
var pushDominoes = function (dominoes) {
    let n = dominoes?.length;
    let leftConsequence = new Array(n)?.fill(-1);
    let rightConsequence = new Array(n)?.fill(-1);
    let newString = '';

    let lastRightSeen = -1;
    for (let i = 0; i < n; i++) {
        switch (dominoes[i]) {
            case 'L':
                rightConsequence[i] = -1;
                lastRightSeen = -1;
                break;
            case 'R':
                rightConsequence[i] = -1;
                lastRightSeen = i;
                break;
            case '.':
                rightConsequence[i] = lastRightSeen != -1 ? i - lastRightSeen : -1;
                break;
        }
    }
    let lastLeftSeen = -1;
    for (let i = n - 1; i >= 0; i--) {
        switch (dominoes[i]) {
            case 'L':
                leftConsequence[i] = -1;
                lastLeftSeen = i;
                break;
            case 'R':
                leftConsequence[i] = -1;
                lastLeftSeen = -1;
                break;
            case '.':
                leftConsequence[i] = lastLeftSeen != -1 ? lastLeftSeen - i : -1;
                break;
        }
    }
    for (let i = 0; i < n; i++) {
        let leftImpact = leftConsequence[i];
        let rightImpact = rightConsequence[i];
        if (leftImpact != rightImpact) {
            let greaterImpact, lesserImpact;
            if (leftImpact > rightImpact) {
                greaterImpact = 'L';
                lesserImpact = 'R';
            } else {
                greaterImpact = 'R';
                lesserImpact = 'L';
            }
            if (leftImpact == -1 || rightImpact == -1) {
                newString += greaterImpact;
            } else {
                newString += lesserImpact;
            }
        } else {
            newString += dominoes[i];
        }
    }
    return newString;
};