//? 3700. Number of ZigZag Arrays II
// You are given three integers n, l, and r.

// A ZigZag array of length n is defined as follows:

// Each element lies in the range [l, r].
// No two adjacent elements are equal.
// No three consecutive elements form a strictly increasing or strictly decreasing sequence.
// Return the total number of valid ZigZag arrays.

// Since the answer may be large, return it modulo 109 + 7.

// A sequence is said to be strictly increasing if each element is strictly greater than its previous one (if exists).

// A sequence is said to be strictly decreasing if each element is strictly smaller than its previous one (if exists).
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    static constexpr long long MOD = 1000000007LL;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix &A, const Matrix &B)
    {
        int n = A.size();
        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++)
        {
            for (int k = 0; k < n; k++)
            {
                if (A[i][k] == 0)
                    continue;

                long long a = A[i][k];

                for (int j = 0; j < n; j++)
                {
                    if (B[k][j] == 0)
                        continue;

                    C[i][j] = (C[i][j] + a * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    Matrix power(Matrix base, long long exp)
    {
        int n = base.size();

        Matrix res(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++)
        {
            res[i][i] = 1;
        }

        while (exp)
        {
            if (exp & 1)
            {
                res = multiply(base, res);
            }
            base = multiply(base, base);
            exp >>= 1;
        }

        return res;
    }

    vector<long long> multiplyMatVec(const Matrix &A,
                                     const vector<long long> &v)
    {
        int n = A.size();
        vector<long long> res(n, 0);

        for (int i = 0; i < n; i++)
        {
            long long cur = 0;

            for (int j = 0; j < n; j++)
            {
                cur = (cur + A[i][j] * v[j]) % MOD;
            }

            res[i] = cur;
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r)
    {
        int m = r - l + 1;
        int sz = 2 * m;

        vector<long long> init(sz, 0);

        for (int x = 1; x <= m; x++)
        {
            init[x - 1] = x - 1;
            init[m + x - 1] = m - x;
        }

        Matrix T(sz, vector<long long>(sz, 0));

        for (int x = 1; x <= m; x++)
        {
            int row = x - 1;

            for (int y = 1; y < x; y++)
            {
                T[row][m + y - 1] = 1;
            }
        }

        for (int x = 1; x <= m; x++)
        {
            int row = m + x - 1;

            for (int y = x + 1; y <= m; y++)
            {
                T[row][y - 1] = 1;
            }
        }

        Matrix P = power(T, n - 2);
        vector<long long> state = multiplyMatVec(P, init);

        long long ans = 0;
        for (long long x : state)
        {
            ans = (ans + x) % MOD;
        }

        return (int)ans;
    }
};