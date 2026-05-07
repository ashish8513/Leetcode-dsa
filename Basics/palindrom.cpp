#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    string str = "ashish";
    string rev = str;
    reverse(rev.begin(), rev.end());

    if (str == rev)
        cout << "The string is a palindrome.";
    else
        cout << "The string is not a palindrome.";

    return 0;
}