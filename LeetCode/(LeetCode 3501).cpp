//? 3501. Maximize Active Section with Trade II

// You are given a binary string s of length n, where:

// '1' represents an active section.
// '0' represents an inactive section.
// You can perform at most one trade to maximize the number of active sections in s. In a trade, you:

// Convert a contiguous block of '1's that is surrounded by '0's to all '0's.
// Afterward, convert a contiguous block of '0's that is surrounded by '1's to all '1's.
// Additionally, you are given a 2D array queries, where queries[i] = [li, ri] represents a substring s[li...ri].

// For each query, determine the maximum possible number of active sections in s after making the optimal trade on the substring s[li...ri].

// Return an array answer, where answer[i] is the result for queries[i].

// Note

// For each query, treat s[li...ri] as if it is augmented with a '1' at both ends, forming t = '1' + s[li...ri] + '1'. The augmented '1's do not contribute to the final count.
// The queries are independent of each other.


#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct Group {
        int start;
        int len;
    };

    class SparseTable {
    public:
        vector<vector<int>> st;
        vector<int> lg;

        SparseTable() {}

        SparseTable(const vector<int>& a) {
            int n = a.size();
            if (n == 0) return;

            lg.assign(n + 1, 0);
            for (int i = 2; i <= n; i++)
                lg[i] = lg[i / 2] + 1;

            st.assign(lg[n] + 1, vector<int>(n));
            st[0] = a;

            for (int k = 1; k <= lg[n]; k++) {
                for (int i = 0; i + (1 << k) <= n; i++) {
                    st[k][i] = max(st[k - 1][i],
                                   st[k - 1][i + (1 << (k - 1))]);
                }
            }
        }

        int query(int l, int r) {
            int k = lg[r - l + 1];
            return max(st[k][l], st[k][r - (1 << k) + 1]);
        }
    };

public:
    vector<int> maxActiveSectionsAfterTrade(string s,
                                            vector<vector<int>>& queries) {

        int ones = count(s.begin(), s.end(), '1');

        vector<Group> zeroGroups;
        vector<int> zeroGroupIndex;

        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '0') {
                if (i && s[i - 1] == '0')
                    zeroGroups.back().len++;
                else
                    zeroGroups.push_back({i, 1});
            }
            zeroGroupIndex.push_back((int)zeroGroups.size() - 1);
        }

        if (zeroGroups.empty())
            return vector<int>(queries.size(), ones);

        vector<int> merge;
        for (int i = 0; i + 1 < (int)zeroGroups.size(); i++)
            merge.push_back(zeroGroups[i].len + zeroGroups[i + 1].len);

        SparseTable st(merge);

        vector<int> ans;

        for (auto &q : queries) {

            int l = q[0];
            int r = q[1];

            int left =
                zeroGroupIndex[l] == -1
                    ? -1
                    : zeroGroups[zeroGroupIndex[l]].len -
                          (l - zeroGroups[zeroGroupIndex[l]].start);

            int right =
                zeroGroupIndex[r] == -1
                    ? -1
                    : r - zeroGroups[zeroGroupIndex[r]].start + 1;

            int startAdjacent = zeroGroupIndex[l] + 1;
            int endAdjacent =
                (s[r] == '1' ? zeroGroupIndex[r] : zeroGroupIndex[r] - 1) - 1;

            int best = ones;

            if (s[l] == '0' && s[r] == '0' &&
                zeroGroupIndex[l] + 1 == zeroGroupIndex[r]) {

                best = max(best, ones + left + right);
            }
            else if (startAdjacent <= endAdjacent) {
                best = max(best,
                           ones + st.query(startAdjacent, endAdjacent));
            }

            if (s[l] == '0' &&
                zeroGroupIndex[l] + 1 <=
                    (s[r] == '1' ? zeroGroupIndex[r]
                                 : zeroGroupIndex[r] - 1)) {

                best = max(best,
                           ones + left +
                               zeroGroups[zeroGroupIndex[l] + 1].len);
            }

            if (s[r] == '0' &&
                zeroGroupIndex[l] < zeroGroupIndex[r] - 1) {

                best = max(best,
                           ones + right +
                               zeroGroups[zeroGroupIndex[r] - 1].len);
            }

            ans.push_back(best);
        }

        return ans;
    }
}; 