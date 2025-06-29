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

//two tortoise method
node* middleNODE(node* head)
{
    node* fast=head;
    node* slow=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}


int main() {
    // Create a linked list
    node* head = new node(10);
    head->next = new node(20);
    head->next->next = new node(30);
    head->next->next->next = new node(40);
    head->next->next->next->next = new node(50);
    head->next->next->next->next->next = new node(60);


    cout << "Original List: ";
    node* current = head;
    while (current != NULL) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout<<"NULL";
    cout << endl;

    // Remove the nth node from the end
    head = middleNODE(head);
    
    cout << "Modified List: ";
    current=head;
    while (current != NULL) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout<<"NULL";
    cout<<endl;

    // cout << "Modified List: ";
    // current = head;
    // cout << current->data<<endl;
    return 0;
}
