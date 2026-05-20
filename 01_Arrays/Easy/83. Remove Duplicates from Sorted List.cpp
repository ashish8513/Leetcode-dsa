// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// approach : 1==1 ->remove
// 1 -> 1 -> 2 -> 3 -> 3

// 1 == 1 → remove duplicate
// 3 == 3 → remove duplicate

// Output:
// 1 -> 2 -> 3
#include <iostream>
#include <climits>

using namespace std;
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr)
            return head;
        ListNode *temp = head;
        while (temp != nullptr && temp->next != nullptr)
        {
            if (temp->val == temp->next->val)
            {
                temp->next = temp->next->next;
            }
            else
            {
                temp = temp->next;
            }
        }
        return head;
    }
};