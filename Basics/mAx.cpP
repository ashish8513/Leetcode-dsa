#include <iostream>
using namespace std;

int main() {

    int arr[] = {3,7,2,9,5};

    int n = 5;

    int maxi = arr[0];

    for(int i = 0; i < n; i++) {

        if(arr[i] > maxi) {

            maxi = arr[i];
        }
    }

    cout << maxi;

    return 0;
}