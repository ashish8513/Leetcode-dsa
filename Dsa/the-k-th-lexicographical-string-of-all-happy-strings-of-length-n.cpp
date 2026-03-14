// A happy string is a string that:

// consists only of letters of the set ['a', 'b', 'c'].
// s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
// For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.

// Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.

// Return the kth string of this list or return an empty string if there are less than k happy strings of length n.

class Solution {
public:
    string getHappyString(int n, int k) {
        vector<array<long long, 3>> order(n + 1);

        order[1][0] = order[1][1] = order[1][2] = 1;
        for(int i = 2; i <= n; i++) {
            long long sum = order[i - 1][0] + order[i - 1][1] + order[i - 1][2];
            for(int j = 0; j < 3; j++) {
                order[i][j] = sum - order[i - 1][j];
            }
        }
        if(accumulate(order[n].begin(), order[n].end(), 0LL) < k) return string();

        string build;
        for(int i = n; i >= 1; i--) {
            for(int j = 0; j < 3; j++) {
                if(!build.empty() && build.back() == j + 'a') continue;

                if(order[i][j] < k) k -= order[i][j];
                else {
                    build.push_back(j + 'a');
                    break;
                }
            }
        }

        return build;
    }
};
