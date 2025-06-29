#include <bits/stdc++.h>
using namespace std;

// revision 1

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

// Function to reverse the doubly linked list using current, forward, backward pointers
Node *reverse(Node *head)
{
    if (!head)
        return nullptr; // Empty list

    Node *current = head;
    Node *forward = nullptr;
    Node *backward = nullptr;

    // Traverse the list
    while (current != nullptr)
    {
        forward = current->next; // Move forward to the next node

        // Swap next and prev for the current node
        current->next = backward;
        current->prev = forward;

        // Move backward to current and current to forward
        backward = current;
        current = forward;
    }

    // After the loop, backward will point to the new head
    return backward;
}

// Function to print the doubly linked list
void printList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // Create a doubly linked list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->prev = head->next->next->next;

    // Print original list
    cout << "Original list: ";
    printList(head);

    // Reverse the list
    head = reverse(head);

    // Print reversed list
    cout << "Reversed list: ";
    printList(head);

    return 0;
}
