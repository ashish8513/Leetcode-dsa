//? 3499. Maximize Active Section with Trade I


// You are given a binary string s of length n, where:

// '1' represents an active section.
// '0' represents an inactive section.
// You can perform at most one trade to maximize the number of active sections in s. In a trade, you:

// Convert a contiguous block of '1's that is surrounded by '0's to all '0's.
// Afterward, convert a contiguous block of '0's that is surrounded by '1's to all '1's.
// Return the maximum number of active sections in s after making the optimal trade.

// Note: Treat s as if it is augmented with a '1' at both ends, forming t = '1' + s + '1'. The augmented '1's do not contribute to the final count.


class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        string t = "1" + s + "1";

        vector<pair<char, int>> runs;

        for (int i = 0; i < t.size();) {
            int j = i;
            while (j < t.size() && t[j] == t[i]) j++;
            runs.push_back({t[i], j - i});
            i = j;
        }

        int base = 0;
        for (char c : s)
            if (c == '1') base++;

        int ans = base;

        for (int i = 1; i + 1 < runs.size(); i++) {
            if (runs[i].first != '1') continue;

            int left = runs[i - 1].second;
            int right = runs[i + 1].second;

            // remove augmented boundary zeros
            if (i - 1 == 0) left--;
            if (i + 1 == (int)runs.size() - 1) right--;

            ans = max(ans, base + left + right);
        }

        return ans;
    }
};