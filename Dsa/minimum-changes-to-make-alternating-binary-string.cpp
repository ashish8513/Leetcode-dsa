// You are given a string s consisting only of the characters '0' and '1'. In one operation, you can change any '0' to '1' or vice versa.

// The string is called alternating if no two adjacent characters are equal. For example, the string "010" is alternating, while the string "0100" is not.

// Return the minimum number of operations needed to make s alternating.

class Solution {
public:
    int minOperations(string s) {
        int count1 = 0;
        int count2 = 0;
        int last1 = '0';
        int last2 = '1';
        for(int i=0;i<s.length();i++){
            if(s[i] != last1){
                count1 ++;
            }
            if(s[i] != last2){
                count2 ++;
            }
            char c = last1;
            last1 = last2;
            last2 = c;
        }
        return min(count1,count2);
    }
};
