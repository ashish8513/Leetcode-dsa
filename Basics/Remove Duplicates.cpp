#include <iostream>
using namespace std;
int main(){
    int arr[]={1,1,2,2,3};
    int n=5;
    for(int i=0;i<n;i++){
        if(arr[i]!=arr[i+1]){
            cout << arr[i] << " ";
        }
    }
    return 0;
}