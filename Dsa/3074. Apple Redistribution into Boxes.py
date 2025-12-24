// You are given an array apple of size n and an array capacity of size m.

// There are n packs where the ith pack contains apple[i] apples. There are m boxes as well, and the ith box has a capacity of capacity[i] apples.

// Return the minimum number of boxes you need to select to redistribute these n packs of apples into boxes.

// Note that, apples from the same pack can be distributed into different boxes.

 class Solution:
    def minimumBoxes(self, apple, capacity):
        total_apples = sum(apple)

        # Sort capacities in descending order
        capacity.sort(reverse=True)

        current_capacity = 0
        boxes_used = 0

        for cap in capacity:
            current_capacity += cap
            boxes_used += 1

            if current_capacity >= total_apples:
                return boxes_used

        return boxes_used
 
