// 142. Linked List Cycle II
//VERY IMPORTANT QUESTION
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
//revision 1
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
        cout << temp->data << " ";
        temp = temp->next;
    }
}

node *detectCycle(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    node *fast = head;
    node *slow = head;
    node *entry = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            while (slow != entry)
            {
                slow = slow->next;
                entry = entry->next;
            }
            return entry;
        }
    }
    return NULL;
}

int main()
{
    // Creating a linked list with nodes
    node *head = new node(3);
    node *second = new node(2);
    node *third = new node(0);
    node *fourth = new node(-4);

    // Connecting the nodes
    head->next = second;
    second->next = third;
    third->next = fourth;

    // Uncomment the below line to create a cycle
    fourth->next = second; // Creates a cycle in the linked list

    // Print the list (won't terminate if there's a cycle)
    // print(head);
    // cout << endl;

    cout<<detectCycle(head);

    return 0;
}
