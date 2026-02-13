# You are given a string s consisting only of the characters 'a', 'b', and 'c'.

# A substring of s is called balanced if all distinct characters in the substring appear the same number of times.

# Return the length of the longest balanced substring of s.

class Solution:
    def longestBalanced(self, s: str) -> int:
        n = len(s)
        p = [[0, 0, 0]]
        for c in s:
            p.append(p[-1][:])
            p[-1]["abc".index(c)] += 1

        ans = 0
        m = {}
        for i, (a, b, c) in enumerate(p):
            for k in [
                (-1, a - b, a - c), 
                (-2, a - b, c),    
                (-3, b - c, a),     
                (-4, c - a, b),     
                (-5, b, c),         
                (-6, c, a),        
                (-7, a, b),         
            ]:
                if not k in m: m[k] = i
                else: ans = max(ans, i - m[k])

        return ans
