# You are given a 0-indexed 2D integer array of events where events[i] = [startTimei, endTimei, valuei]. The ith event starts at startTimei and ends at endTimei, and if you attend this event, you will receive a value of valuei. You can choose at most two non-overlapping events to attend such that the sum of their values is maximized.

# Return this maximum sum.

# Note that the start time and end time is inclusive: that is, you cannot attend two events where one of them starts and the other ends at the same time. More specifically, if you attend an event with end time t, the next event must start at or after t + 1.

 from bisect import bisect_left

class Solution:
    def maxTwoEvents(self, events):
        # Step 1: sort events by start time
        events.sort(key=lambda x: x[0])
        n = len(events)

        # Step 2: build suffix max array for values
        suffix_max = [0] * (n + 1)
        for i in range(n - 1, -1, -1):
            suffix_max[i] = max(suffix_max[i + 1], events[i][2])

        # Step 3: extract start times for binary search
        start_times = [event[0] for event in events]

        ans = 0

        # Step 4: try each event as first event
        for i in range(n):
            start, end, value = events[i]

            # binary search for next valid event
            idx = bisect_left(start_times, end + 1)

            # total value = current event + best possible next event
            total = value + suffix_max[idx]
            ans = max(ans, total)

        return ans
