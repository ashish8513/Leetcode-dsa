// You are given a binary string s. You are allowed to perform two types of operations on the string in any sequence:

// Type-1: Remove the character at the start of the string s and append it to the end of the string.
// Type-2: Pick any character in s and flip its value, i.e., if its value is '0' it becomes '1' and vice-versa.
// Return the minimum number of type-2 operations you need to perform such that s becomes alternating.

// The string is called alternating if no two adjacent characters are equal.

// For example, the strings "010" and "1010" are alternating, while the string "0100" is not.

class Solution {
public:
    int minFlips(string s) {
        int size = s.length();
        int minimumOpe = INT_MAX;

        int oddZero = 0, oddOne = 0;
        int evenZero = 0, evenOne = 0;

        for(int i = 0; i < size; i++) {
            if(i % 2 == 0) {
                if(s[i] == '0') evenZero++;
                else evenOne++;
            } 
            else {
                if(s[i] == '0') oddZero++;
                else oddOne++;
            }
        }

        for(int i = 0; i < size; i++) {

            int sum1 = oddOne + evenZero;

            int sum2 = evenOne + oddZero;

            int req1 = size - sum1;
            int req2 = size - sum2;

            minimumOpe = min(minimumOpe, min(req1, req2));

            swap(oddOne, evenOne);
            swap(oddZero, evenZero);

            if((size - 1) % 2 == 0) {
                if(s[i] == '1') {
                    evenOne++;
                    oddOne--;
                } 
                else {
                    evenZero++;
                    oddZero--;
                }
            }
        }

        return minimumOpe;
    }
};
