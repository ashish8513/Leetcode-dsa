// Given a binary matrix mat[][] containing only 0s and 1s, find the total coverage of all 0's. The coverage of a particular 0 cell is defined by checking 1's in its four directions (left, right, up, and down). For each direction, if there is at least one 1 anywhere between the 0 and the boundary of the matrix, the coverage increases by one.

// Return the sum of the coverage values for all 0 cells in the matrix.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findCoverage(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (mat[i][j] != 0) continue;

                // Left
                for (int c = j - 1; c >= 0; c--) {
                    if (mat[i][c] == 1) {
                        ans++;
                        break;
                    }
                }

                // Right
                for (int c = j + 1; c < m; c++) {
                    if (mat[i][c] == 1) {
                        ans++;
                        break;
                    }
                }

                // Up
                for (int r = i - 1; r >= 0; r--) {
                    if (mat[r][j] == 1) {
                        ans++;
                        break;
                    }
                }

                // Down
                for (int r = i + 1; r < n; r++) {
                    if (mat[r][j] == 1) {
                        ans++;
                        break;
                    }
                }
            }
        }

        return ans;
    }
}; 