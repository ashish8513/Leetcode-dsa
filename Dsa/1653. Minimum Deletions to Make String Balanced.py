# You are given a string s consisting only of characters 'a' and 'b'​​​​.

# You can delete any number of characters in s to make s balanced. s is balanced if there is no pair of indices (i,j) such that i < j and s[i] = 'b' and s[j]= 'a'.

# Return the minimum number of deletions needed to make s balanced.

 class Solution:
    def minimumDeletions(self, s: str) -> int:
        b_count = 0      # number of 'b's seen so far
        deletions = 0    # minimum deletions needed

        for ch in s:
            if ch == 'b':
                b_count += 1
            else:  # ch == 'a'
                # Either delete this 'a' (deletions + 1)
                # OR delete all previous 'b's (b_count)
                deletions = min(deletions + 1, b_count)

        return deletions
