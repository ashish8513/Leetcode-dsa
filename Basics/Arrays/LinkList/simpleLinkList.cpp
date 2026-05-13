#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

int main()
{
    Node* first = new Node();

    first->data = 10;
    first->next = NULL;

    cout << first->data;

    return 0;
}