// Input:
// [0,1,0,3,12]

// Output:
// [1,3,12,0,0]

#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int arr[] = {0, 1, 0, 3, 12};
    int n = 5;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[count], arr[i]);
            count++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}