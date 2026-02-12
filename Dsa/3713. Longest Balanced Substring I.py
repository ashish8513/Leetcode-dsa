# You are given a string s consisting of lowercase English letters.

# A substring of s is called balanced if all distinct characters in the substring appear the same number of times.

# Return the length of the longest balanced substring of s.

class Solution:
    def longestBalanced(self, s: str) -> int:
        n = len(s)
        ans = 0
        
        for i in range(n):
            freq = [0] * 26
            distinct = 0
            max_freq = 0
            
            for j in range(i, n):
                idx = ord(s[j]) - ord('a')
                
                if freq[idx] == 0:
                    distinct += 1
                    
                freq[idx] += 1
                max_freq = max(max_freq, freq[idx])
                
                length = j - i + 1
                
                # Check balanced condition
                if length == distinct * max_freq:
                    ans = max(ans, length)
        
        return ans
