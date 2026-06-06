// Given two integers n and m representing the dimensions of a chessboard, find the number of ways to place one black knight and one white knight on the chessboard such that they cannot attack each other.

// Note:

// The knights have to be placed on different squares.
// A knight can move two squares horizontally and one square vertically (L shaped), or two squares vertically and one square horizontally (L shaped).
// The knights attack each other if one can reach the other in one move.

class Solution {
public:
    long long numOfWays(int n, int m) {
        long long cells = 1LL * n * m;

        long long total = cells * (cells - 1);

        long long attacking = 0;

        if (n >= 2 && m >= 3)
            attacking += 1LL * (n - 1) * (m - 2);

        if (n >= 3 && m >= 2)
            attacking += 1LL * (n - 2) * (m - 1);

        attacking *= 4;

        return total - attacking;
    }
};