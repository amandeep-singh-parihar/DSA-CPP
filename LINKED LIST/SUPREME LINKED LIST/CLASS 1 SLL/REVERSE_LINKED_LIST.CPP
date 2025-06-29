#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// reverse linked list using recursion
// revision 1

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

node *reverse(node *&prev, node *&curr)
{
    if (curr == nullptr)
    {
        return prev;
    }

    node *forward = curr->next;
    curr->next = prev;

    reverse(curr, forward);
}

void print(node *&head)
{
    node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    node *head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);

    // Print original list
    cout << "Original list: ";
    print(head);

    // Reverse the list
    node *prev = nullptr;
    head = reverse(prev, head);

    // Print reversed list
    cout << "Reversed list: ";
    print(head);

    return 0;
}
