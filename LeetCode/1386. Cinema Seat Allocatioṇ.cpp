// A cinema has n rows of seats, numbered from 1 to n. Each row has 10 seats, numbered from 1 to 10.

// You are given a 2D integer array reservedSeats, where reservedSeats[i] = [rowi, seati] means that seat seati in row rowi is already reserved.

// A four-person group must be assigned to four seats in the same row. The group can be seated in one of the following seat blocks:

// seats 2, 3, 4, 5
// seats 4, 5, 6, 7
// seats 6, 7, 8, 9
// A block can be used only if none of its seats are reserved. Each seat can be assigned to at most one group.

// Return an integer denoting the maximum number of four-person groups that can be assigned.
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        unordered_map<int, set<int>> reserved;

        for (auto seat : reservedSeats) {
            reserved[seat[0]].insert(seat[1]);
        }

        int ans = (n - reserved.size()) * 2;

        for (auto& [row, seats] : reserved) {
            
            bool left  = true;  // 2,3,4,5
            bool middle = true; // 4,5,6,7
            bool right = true;  // 6,7,8,9

            for (int s : seats) {
                if (s >= 2 && s <= 5)
                    left = false;

                if (s >= 4 && s <= 7)
                    middle = false;

                if (s >= 6 && s <= 9)
                    right = false;
            }

            if (left && right)
                ans += 2;
            else if (left || middle || right)
                ans += 1;
        }

        return ans;
    }
};
