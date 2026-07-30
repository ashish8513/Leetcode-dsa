//? Maximum Subset XOR

// Given an array arr[], choose any subset of elements (possibly all elements) such that the XOR of the chosen elements is maximized.

class Solution {
public:
    int maxSubsetXOR(vector<int> &arr) {
        int n = arr.size();
        int index = 0;

        for (int bit = 31; bit >= 0; bit--) {
            int maxIndex = -1;

            for (int i = index; i < n; i++) {
                if ((arr[i] & (1 << bit)) != 0) {
                    maxIndex = i;
                    break;
                }
            }

            if (maxIndex == -1)
                continue;

            swap(arr[index], arr[maxIndex]);

            for (int i = 0; i < n; i++) {
                if (i != index && (arr[i] & (1 << bit))) {
                    arr[i] ^= arr[index];
                }
            }

            index++;
        }

        int ans = 0;
        for (int x : arr)
            ans = max(ans, ans ^ x);

        return ans;
    }
}; 