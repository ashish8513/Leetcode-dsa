// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// Online C++ compiler to run C++ program online
// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>

int main() {
  int arr[]={1,1,2,2,3};
  int unique=0;
  int n= 5;
  int curr=1;
  while(curr<n){
      if(arr[curr]==arr[unique]){
          curr++ ;
      }else{
          arr[unique+1]=arr[curr];
          unique++;
          curr++;
      }
  }
     for(int i=0;i<=unique;i++){
         std::cout << arr[i] << " ";
      }
    return unique;
}