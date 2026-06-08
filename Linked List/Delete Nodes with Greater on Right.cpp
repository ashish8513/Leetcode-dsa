// Given a singly linked list, remove all nodes that have a node with a greater value anywhere to their right in the list. Return the head of the modified linked list.

//  Structure of a Linked List node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};


#include <iostream>
using namespace std;
class Solution {
public:
    
    Node* reverseList(Node* head) {
        Node* prev = NULL;
        Node* curr = head;

        while (curr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    Node *compute(Node *head) {
        if (head == NULL || head->next == NULL)
            return head;

        // Reverse the list
        head = reverseList(head);

        Node* curr = head;
        int maxSoFar = curr->data;

        while (curr && curr->next) {
            if (curr->next->data < maxSoFar) {
                Node* temp = curr->next;
                curr->next = temp->next;
                delete temp;
            } else {
                curr = curr->next;
                maxSoFar = curr->data;
            }
        }

        // Reverse again to restore order
        head = reverseList(head);

        return head;
    }
};