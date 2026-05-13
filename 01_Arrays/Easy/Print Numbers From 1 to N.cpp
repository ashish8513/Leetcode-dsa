// Given a number n, print numbers from:

#include <iostream>
using namespace std;

int sum(int n)
{
    // Base Case
    if(n == 0)
    {
        return 0;
    }

    // Recursive Case
    return (n % 10) + sum(n / 10);
}

int main()
{
    int n = 1234;

    cout << sum(n);

    return 0;
}