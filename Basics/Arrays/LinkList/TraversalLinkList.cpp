#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
int main()
{
    Node *first = new Node();
    Node *second = new Node();
    Node *third = new Node();

    first->data = 10;
    first->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;
    Node *temp = first;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}