// Given an array arr[]  and a range from l to r, the task is to count the number of triplets having a sum in the range [l, r].

class Solution {
public:

    long long countLessEqual(vector<int>& arr, int target) {
        int n = arr.size();
        long long count = 0;

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                long long sum = 1LL * arr[i] + arr[left] + arr[right];

                if (sum <= target) {
                   
                    count += (right - left);
                    left++;
                } 
                else {
                    right--;
                }
            }
        }

        return count;
    }

    int countTriplets(vector<int> &arr, int l, int r) {
        sort(arr.begin(), arr.end());

        long long ans = countLessEqual(arr, r) 
                      - countLessEqual(arr, l - 1);

        return ans;
    }
};
