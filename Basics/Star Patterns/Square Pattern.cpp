// 1234
// 1234
// 1234
// 1234

#include <iostream>
using namespace std;
int main()
{
    int n = 4;
    for (int i = 0; i < n; i++) // outer
    {
        char ch = 'A';
        for (int j = 0; j < n; j++) // inner start => line start
        {
            cout << ch;
            ch = ch + 1; //char + int
        }
        cout << endl;
    }
    return 0;
}

// i=0;
// j=0;

// for(int i = 1to n) n times
// i=0 to n-1