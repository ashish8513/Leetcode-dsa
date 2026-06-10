// You are given an integer array nums of length n and an integer k.

// You must select exactly k distinct subarrays nums[l..r] of nums. Subarrays may overlap, but the exact same subarray (same l and r) cannot be chosen more than once.

// The value of a subarray nums[l..r] is defined as: max(nums[l..r]) - min(nums[l..r]).

// The total value is the sum of the values of all chosen subarrays.

// Return the maximum possible total value you can achieve.

class SparseTableRMQ {
public:
    int n, maxLog;
    vector<vector<int>> mx, mn;
    vector<int> lg;

    SparseTableRMQ(vector<int>& nums) {
        n = nums.size();
        maxLog = 32 - __builtin_clz(n) + 1;

        mx.assign(n, vector<int>(maxLog));
        mn.assign(n, vector<int>(maxLog));
        lg.assign(n + 1, 0);

        for (int i = 2; i <= n; i++) {
            lg[i] = lg[i >> 1] + 1;
        }

        for (int i = 0; i < n; i++) {
            mx[i][0] = nums[i];
            mn[i][0] = nums[i];
        }

        for (int j = 1; j < maxLog; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                mx[i][j] =
                    max(mx[i][j - 1],
                        mx[i + (1 << (j - 1))][j - 1]);

                mn[i][j] =
                    min(mn[i][j - 1],
                        mn[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int queryMax(int l, int r) {
        int k = lg[r - l + 1];
        return max(mx[l][k],
                   mx[r - (1 << k) + 1][k]);
    }

    int queryMin(int l, int r) {
        int k = lg[r - l + 1];
        return min(mn[l][k],
                   mn[r - (1 << k) + 1][k]);
    }
};

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        SparseTableRMQ st(nums);

        using T = tuple<long long, int, int>;

        auto cmp = [](const T& a, const T& b) {
            return get<0>(a) < get<0>(b);
        };

        priority_queue<T, vector<T>, decltype(cmp)> pq(cmp);

        // Har l ke liye largest element push karo
        for (int l = 0; l < n; l++) {
            long long val =
                1LL * st.queryMax(l, n - 1) -
                st.queryMin(l, n - 1);

            pq.push({val, l, n - 1});
        }

        long long ans = 0;

        for (int i = 0; i < k; i++) {
            auto [val, l, r] = pq.top();
            pq.pop();

            ans += val;

            if (r > l) {
                long long nxt =
                    1LL * st.queryMax(l, r - 1) -
                    st.queryMin(l, r - 1);

                pq.push({nxt, l, r - 1});
            }
        }

        return ans;
    }
}; 