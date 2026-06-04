// Substring with Max Zero-One Diff Difficulty: MediumAccuracy: 53.05%Submissions: 47K+Points: 4 Given a binary string s consisting of 0s and 1s. Find the maximum difference of the number of 0s and the number of 1s (number of 0s – number of 1s) in a substring of the string. Note: In the case of all 1s, the answer will be -1.in c++

class Solution
{
public:
    int maxSubstring(string s)
    {
        int currSum = 0;
        int maxSum = -1;

        for (char ch : s)
        {
            int val = (ch == '0') ? 1 : -1;

            currSum = max(val, currSum + val);
            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }
};