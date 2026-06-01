// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

#include <iostream>

// Definition for singly-linked list node.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Base case: if the list is empty or has only one element
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode* current = head;
        
        // Traverse the list until the second to last node
        while (current != nullptr && current->next != nullptr) {
            // If the current node value matches the next node value
            if (current->val == current->next->val) {
                ListNode* duplicate = current->next;
                current->next = current->next->next; // Skip the duplicate node
                delete duplicate;                    // Free memory to prevent leaks
            } else {
                // Only advance pointer if no duplicate was found
                current = current->next;
            }
        }
        
        return head;
    }
};
