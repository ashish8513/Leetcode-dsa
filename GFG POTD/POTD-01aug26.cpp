// Max After m Range Increments
// Difficulty: MediumAccuracy: 49.92%Submissions: 19K+Points: 4
// Given three arrays a[], b[], and k[], representing m range increment operations on an array arr[] of size n, where all elements of arr[] are initially 0.

// Increment(a[i], b[i], k[i]) adds k[i] to each element arr[j] such that a[i] ≤ j ≤ b[i] (mainly indexes in range from a[i] to b[i])
// After performing all the given operations, find the maximum value present in the array.

class Solution {
public:
    int findMax(int n, vector<int>& a, vector<int>& b, vector<int>& k) {

        vector<int> diff(n + 1, 0);

        int m = a.size();

        for (int i = 0; i < m; i++) {
            diff[a[i]] += k[i];

            if (b[i] + 1 < n)
                diff[b[i] + 1] -= k[i];
        }

        int curr = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            curr += diff[i];
            ans = max(ans, curr);
        }

        return ans;
    }
}; 