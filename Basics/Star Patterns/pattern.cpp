#include <iostream>
using namespace std;
int main()
{
    int num = 6;
    for (int i = 3; i >= 1; i--) // outer
    {
        // spaces
        for (int s = 3; s > i; s--)
        {
            cout << "-" << " ";
        }
        // number
        for (int j = 1; j <= i; j++) // innner
        {
            cout << num << " ";
            num--;
        }
        cout << endl;
    }
    return 0;
}