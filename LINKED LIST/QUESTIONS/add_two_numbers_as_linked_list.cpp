#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

node* add_two_numbers_as_a_linked_list(node* &l1,node* &l2)
{
    node* dummy=new node(0);
    node* temp=dummy;
    int carry=0;
    while(l1!=NULL || l2!=NULL || carry)
    {
        int sum=0;
        if(l1!=NULL)
        {
            sum+=l1->data;
            l1=l1->next;
        }

        if(l2!=NULL)
        {
            sum+=l2->data;
            l2=l2->next;
        }

        sum+=carry;
        carry=sum/10;
        node* sumnode=new node(sum%10);
        temp->next= sumnode;
        temp=temp->next;
    }
    return dummy->next;
}

void print_list(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}


int main() {
    // Create two linked lists representing two numbers
    node* l1 = new node(2);
    l1->next = new node(4);
    l1->next->next = new node(3);

    node* l2 = new node(5);
    l2->next = new node(6);
    l2->next->next = new node(4);

    cout << "List 1: ";
    print_list(l1);

    cout << "List 2: ";
    print_list(l2);

    // Add the two numbers represented by the linked lists
    node* result = add_two_numbers_as_a_linked_list(l1, l2);

    cout << "Result: ";
    print_list(result);

    return 0;
}