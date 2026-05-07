#include <iostream>
using namespace std;

int main() {

    string str = "education";

    int count = 0;

    for(int i = 0; i < str.length(); i++) {

        char ch = str[i];

        if(ch == 'a' || ch == 'e' || ch == 'i' ||
           ch == 'o' || ch == 'u') {

            count++;
        }
    }

    cout << "Vowels: " << count;

    return 0;
}