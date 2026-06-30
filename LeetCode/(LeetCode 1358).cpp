//? 1358. Number of Substrings Containing All Three Characters
// Given a string s consisting only of characters a, b and c.

// Return the number of substrings containing at least one occurrence of all these characters a, b and c.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> cnt(3, 0);

        int left = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {
            cnt[s[right] - 'a']++;

            while (cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0) {
                ans += (n - right);
                cnt[s[left] - 'a']--;
                left++;
            }
        }

        return ans;
    }
}; 