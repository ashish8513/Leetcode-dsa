# You are given an array of n strings strs, all of the same length.

# We may choose any deletion indices, and we delete all the characters in those indices for each string.

# For example, if we have strs = ["abcdef","uvwxyz"] and deletion indices {0, 2, 3}, then the final array after deletions is ["bef", "vyz"].

# Suppose we chose a set of deletion indices answer such that after deletions, the final array has its elements in lexicographic order (i.e., strs[0] <= strs[1] <= strs[2] <= ... <= strs[n - 1]). Return the minimum possible value of answer.length.

 

class Solution:
    def minDeletionSize(self, strs):
        n = len(strs)
        m = len(strs[0])
        sorted_pairs = [False] * (n - 1)
        deletions = 0

        for col in range(m):
            bad = False
            for i in range(n - 1):
                if not sorted_pairs[i] and strs[i][col] > strs[i + 1][col]:
                    bad = True
                    break

            if bad:
                deletions += 1
                continue

            for i in range(n - 1):
                if not sorted_pairs[i] and strs[i][col] < strs[i + 1][col]:
                    sorted_pairs[i] = True

            if all(sorted_pairs):
                break

        return deletions
