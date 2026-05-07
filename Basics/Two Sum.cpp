#include <iostream>
using namespace std;
int main() {
    int arr[]={1,2,3,4,5};
    int n= 5;
    int largest=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
    }
    cout << "Largest element in the array is: " << largest;
    return 0;
}