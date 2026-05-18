#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    // Vertical Scanning - OPTIMIZED APPROACH
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty()) return "";

        // Compare character by character at each position (column-wise)
        for (size_t i = 0; i < strs[0].length(); i++)
        {
            char ch = strs[0][i]; // Pehli string ka character

            // Check if this character exists at position i in ALL strings
            for (size_t j = 1; j < strs.size(); j++)
            {
                // Agar position exceed ho gaya ya character match nahi hua
                if (i >= strs[j].length() || strs[j][i] != ch)
                {
                    return strs[0].substr(0, i); // Return prefix till now
                }
            }
        }
        return strs[0]; // Agar puri pehli string common prefix hai
    }
};

int main()
{
    Solution sol;

    // Test Case 1: Simple common prefix
    vector<string> test1 = {"flower", "flow", "flight"};
    cout << "Test 1: " << sol.longestCommonPrefix(test1) << endl; // Output: "fl"

    // Test Case 2: No common prefix
    vector<string> test2 = {"dog", "racecar", "car"};
    cout << "Test 2: '" << sol.longestCommonPrefix(test2) << "'" << endl; // Output: ""

    // Test Case 3: Single character common
    vector<string> test3 = {"interspecies", "interstellar", "interstate"};
    cout << "Test 3: " << sol.longestCommonPrefix(test3) << endl; // Output: "inters"

    // Test Case 4: Full string is common
    vector<string> test4 = {"abc", "abc", "abc"};
    cout << "Test 4: " << sol.longestCommonPrefix(test4) << endl; // Output: "abc"

    // Test Case 5: Single string
    vector<string> test5 = {"hello"};
    cout << "Test 5: " << sol.longestCommonPrefix(test5) << endl; // Output: "hello"

    return 0;
}