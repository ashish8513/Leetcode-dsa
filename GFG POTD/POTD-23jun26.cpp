//? Maximum Number of People Defeated

// There are infinitely many people standing in a row, indexed from 1. The strength of the person at index i is i².

// Given a strength p, determine the maximum number of people that can be defeated. A person with strength x can be defeated only if p ≥ x, after which the strength p decreases by x. 

class Solution {
  public:
    int maxPeopleDefeated(int p) {
        long long lo = 0, hi = 100000, ans = 0;

        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;

            long long sum = mid * (mid + 1) * (2 * mid + 1) / 6;

            if (sum <= p) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return (int)ans;
    }
}; 