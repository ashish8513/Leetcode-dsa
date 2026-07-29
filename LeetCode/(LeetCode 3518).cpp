//? 3518. Smallest Palindromic Rearrangement II

// You are given a palindromic string s and an integer k.

// Return the k-th lexicographically smallest palindromic permutation of s. If there are fewer than k distinct palindromic permutations, return an empty string.

// Note: Different rearrangements that yield the same palindromic string are considered identical and are counted once.

class Solution {
public:
    using int64 = long long;

    int64 mulCap(int64 a, int64 b, int64 cap) {
        __int128 x = (__int128)a * b;
        if (x >= cap) return cap;
        return (int64)x;
    }

    int64 combCap(int n, int r, int64 cap) {
        if (r < 0 || r > n) return 0;
        r = min(r, n - r);

        int64 res = 1;
        for (int i = 1; i <= r; i++) {
            int64 num = n - r + i;
            int64 den = i;

            int64 g = std::gcd(num, den);
            num /= g;
            den /= g;

            g = std::gcd(res, den);
            res /= g;
            den /= g;

            res = mulCap(res, num, cap);
            res /= den;

            if (res >= cap) return cap;
        }
        return res;
    }

    int64 countWays(vector<int> &cnt, int64 cap) {
        int rem = 0;
        int64 ways = 1;

        for (int c : cnt) {
            if (c == 0) continue;
            int64 cur = combCap(rem + c, c, cap);
            ways = mulCap(ways, cur, cap);
            if (ways >= cap) return cap;
            rem += c;
        }
        return ways;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for (char ch : s) freq[ch - 'a']++;

        vector<int> half(26, 0);
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            if (freq[i] & 1) mid = char('a' + i);
        }

        int halfLen = s.size() / 2;
        int64 cap = (int64)k + 1;

        if (countWays(half, cap) < k) return "";

        string left;

        for (int pos = 0; pos < halfLen; pos++) {
            for (int c = 0; c < 26; c++) {
                if (half[c] == 0) continue;

                half[c]--;
                int64 ways = countWays(half, cap);

                if (ways >= k) {
                    left.push_back(char('a' + c));
                    break;
                } else {
                    k -= ways;
                    half[c]++;
                }
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        if (mid) return left + string(1, mid) + right;
        return left + right;
    }
}; 