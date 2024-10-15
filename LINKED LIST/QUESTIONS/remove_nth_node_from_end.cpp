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

node* remove_nth_node_from_end(node* head,int n)
{
    node* temp=new node(10);
    temp->next=head;
    node* fast=temp;
    node* slow=temp;
    for(int i=1;i<=n;++i)
    {
        fast=fast->next;
    }

    while(fast->next!=NULL)
    {
        fast=fast->next;
        slow=slow->next;
    }

    slow->next=slow->next->next;

    return temp->next;

}

int main() {
    // Create a linked list
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);

    cout<<"enter the value of n : ";
    int n; // Remove the 2nd node from the end
    cin>>n;

    cout << "Original List: ";
    node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    // Remove the nth node from the end
    head = remove_nth_node_from_end(head, n);

    cout << "Modified List: ";
    current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}
