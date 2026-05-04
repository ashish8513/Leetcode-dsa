#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// function
int findSecondSmallest(const vector<int>& nums) {
    int smallest = numeric_limits<int>::max();
    int secondSmallest = numeric_limits<int>::max();

    for (int num : nums) {
        if (num < smallest) {
            secondSmallest = smallest;
            smallest = num;
        } else if (num > smallest && num < secondSmallest) {
            secondSmallest = num;
        }
    }

    return secondSmallest;
}

int main() {
    vector<int> nums = {5,2,8,1,3};

    int result = findSecondSmallest(nums);

    cout << "Second smallest: " << result << endl;

    return 0;
}