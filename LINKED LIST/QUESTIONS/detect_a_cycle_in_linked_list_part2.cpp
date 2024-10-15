#include <bits/stdc++.h>
using namespace std;

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

node *detect_a_cycle_in_linked_list(node *&head)
{
    if (head == NULL || head->next == NULL)
        return NULL;

    node *fast = head;
    node *slow = head;
    node *entry = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
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
    // Create a sample linked list to test for cycle detection
    node* head = new node(1);
    node* second = new node(2);
    node* third = new node(3);
    node* fourth = new node(4);
    node* fifth = new node(5);
    node* sixth = new node(6);
    node* seventh = new node(7);


    head->next = second;
    second->next = third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=sixth;
    sixth->next=seventh;


    // Uncomment the following lines to create a cycle for testing
    seventh->next = fifth;

    node* hasCycle = detect_a_cycle_in_linked_list(head);
    cout<<hasCycle->data;

    return 0;
}