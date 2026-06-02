// You are given two categories of theme park attractions: land rides and water rides.

// Land rides
// landStartTime[i] – the earliest time the ith land ride can be boarded.
// landDuration[i] – how long the ith land ride lasts.
// Water rides
// waterStartTime[j] – the earliest time the jth water ride can be boarded.
// waterDuration[j] – how long the jth water ride lasts.
// A tourist must experience exactly one ride from each category, in either order.

// A ride may be started at its opening time or any later moment.
// If a ride is started at time t, it finishes at time t + duration.
// Immediately after finishing one ride the tourist may board the other (if it is already open) or wait until it opens.
// Return the earliest possible time at which the tourist can finish both rides.
class Solution {
public:
    // Dono categories ke liye yahi helper use hoga
    // finish_first = pehli ride khatam hone ka time
    // starts, durs = doosri category ke rides
    int bestSecond(int finish_first, vector<int>& starts, vector<int>& durs) {
        int best = INT_MAX;
        for (int i = 0; i < starts.size(); i++) {
            // Agar ride already open hai to seedha board karo, warna wait karo
            int finish = max(finish_first, starts[i]) + durs[i];
            best = min(best, finish);
        }
        return best;
    }

    // Ek category mein sabse jaldi khatam hone wali ride ka time
    int minFinish(vector<int>& starts, vector<int>& durs) {
        int best = INT_MAX;
        for (int i = 0; i < starts.size(); i++) {
            best = min(best, starts[i] + durs[i]);
        }
        return best;
    }

    int earliestFinishTime(
        vector<int>& landStartTime, vector<int>& landDuration,
        vector<int>& waterStartTime, vector<int>& waterDuration
    ) {
        // Order 1: pehle land, phir water
        int landEnd  = minFinish(landStartTime, landDuration);
        int order1   = bestSecond(landEnd, waterStartTime, waterDuration);

        // Order 2: pehle water, phir land
        int waterEnd = minFinish(waterStartTime, waterDuration);
        int order2   = bestSecond(waterEnd, landStartTime, landDuration);

        return min(order1, order2);
    }
};