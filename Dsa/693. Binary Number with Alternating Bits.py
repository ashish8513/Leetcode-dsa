# Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        bin_n=bin(n)

        if len(bin_n)==1:
            return True
        for i in range(1,len(bin_n)):
            if bin_n[i-1]==bin_n[i]:
                return False
        
        return True
