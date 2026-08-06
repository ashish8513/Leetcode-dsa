//? Minimum Increment or Double Operations to Convert
// Given an array arr[]. Initially, you have another array containing only 0s.
// In one operation, you may either:

// Choose any one element and increase its value by 1, or
// Double the values of all elements in the array simultaneously.
// Find the minimum number of operations required to transform the initial all-zero array into the given array arr[]. 

class Solution {
  public:
    int countMinOperations(vector<int>& arr) {
        int ans = 0;

        while (true) {
            bool allZero = true;

            // Remove odd values
            for (int i = 0; i < arr.size(); i++) {
                if (arr[i] % 2 == 1) {
                    arr[i]--;
                    ans++;
                }
                if (arr[i] != 0)
                    allZero = false;
            }

            if (allZero)
                break;

            // Divide all by 2
            for (int i = 0; i < arr.size(); i++)
                arr[i] /= 2;

            ans++;
        }

        return ans;
    }
};