// 83. Remove Duplicates from Sorted List
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

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

void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

node *deleteDuplicates(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *curr = head;

    // Iterate through the list to remove duplicates
    while (curr != NULL && curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            // Duplicate found, remove the next node
            node *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        else
        {
            // Move to the next node if no duplicate
            curr = curr->next;
        }
    }

    return head;
}

int main()
{
    // Creating a linked list with some duplicates
    node *head = new node(10);
    node *second = new node(20);
    node *third = new node(20); // duplicate
    node *fourth = new node(30);
    node *fifth = new node(40);
    node *sixth = new node(40); // duplicate
    node *seventh = new node(40);
    node *eight = new node(40);
    node *ninth = new node(70);

    // Linking the nodes together
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eight;
    eight->next = ninth;

    cout << endl;
    print(head); // Print original list
    cout << endl;

    // Remove duplicates
    node *ans = deleteDuplicates(head);

    // cout << "List after removing duplicates: ";
    cout << endl;
    print(ans); // Print list after removing duplicates
    cout << endl;

    return 0;
}