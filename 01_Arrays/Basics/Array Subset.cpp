// Given two arrays a[] and b[], your task is to determine whether b[] is a subset of a[].

// Examples:

// Input: a[] = [11, 7, 1, 13, 21, 3, 7, 3], b[] = [11, 3, 7, 1, 7]
// Output: true
// Explanation: b[] is a subset of a[]

class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        for(int i =0;i<b.size();i++){
            bool found = false;
            for(int j = 0; j <a.size(); j++){
                if(b[i]==a[j]){
                    found= true;
                    break;
                }
            }
            if(found == false){
                return false;
            }
        }
        return true;
    }
};