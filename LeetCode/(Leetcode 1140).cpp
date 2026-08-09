//? 1140. Stone Game II

// Alice and Bob continue their games with piles of stones. There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i]. The objective of the game is to end with the most stones.

// Alice and Bob take turns, with Alice starting first.

// On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M. Then, we set M = max(M, X). Initially, M = 1.

// The game continues until all the stones have been taken.

// Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.

class Solution {
public:
    int n;
    vector<int> suffix;
    vector<vector<int>> dp;

    int solve(int i, int M) {

        // Saare remaining piles le sakte hain
        if (i >= n)
            return 0;

        // Agar 2*M remaining piles se zyada/equal hain,
        // current player sab le sakta hai
        if (2 * M >= n - i)
            return suffix[i];

        if (dp[i][M] != -1)
            return dp[i][M];

        int ans = 0;

        // X = number of piles current player takes
        for (int X = 1; X <= 2 * M; X++) {

            int newM = max(M, X);

            // Current player gets:
            // remaining total - opponent's maximum
            int current = suffix[i] - solve(i + X, newM);

            ans = max(ans, current);
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {

        n = piles.size();

        // Suffix sum
        suffix.resize(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        dp.assign(n, vector<int>(n + 1, -1));

        return solve(0, 1);
    }
};