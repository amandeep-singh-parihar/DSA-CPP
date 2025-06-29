#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* next;
    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

bool detect_a_cycle_in_linked_list(node* &head)
{
    if(head==NULL || head->next==NULL) return false;

    node* f=head;
    node* s=head;
    
    while(f->next!=NULL && f->next->next!=NULL)
    {
        f=f->next->next;
        s=s->next;
        if(s==f)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    // Create a sample linked list to test for cycle detection
    node* head = new node(1);
    node* second = new node(2);
    node* third = new node(3);

    head->next = second;
    second->next = third;

    // Uncomment the following lines to create a cycle for testing
    third->next = head;

    bool hasCycle = detect_a_cycle_in_linked_list(head);

    if (hasCycle) {
        cout << "The linked list has a cycle." << endl;
    } else {
        cout << "The linked list does not have a cycle." << endl;
    }

    return 0;
}