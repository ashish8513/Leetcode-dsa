#include <iostream>
using namespace std;
int main()
{
    int n = 5;
    int fact = 1;
    for (int i = 1; i < n; i++)
    {
        fact = fact * i;
    }
    cout << "The factorial of " << n << " is: " << fact << endl;
    return 0;
}