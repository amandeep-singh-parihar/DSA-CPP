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

node* mergeLL(node* &l1, node* &l2)
{
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;

    node* temp=new node(0);
    node* res=temp;

    
    while(l1!=NULL && l2!=NULL)
    {
        if(l1->data<=l2->data)
        {
            temp->next=l1;
            temp=temp->next;
            l1=l1->next;
        }else{
            temp->next=l2;
            temp=temp->next;
            l2=l2->next;
        }
    }
    if(l1)
    {
        temp->next=l1;
    }else{
        temp->next=l2;
    }

    return res->next;
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

int main()
{
    // Create two linked lists
    node *l1 = new node(1);
    l1->next = new node(3);
    l1->next->next = new node(5);

    node *l2 = new node(2);
    l2->next = new node(4);
    l2->next->next = new node(6);

    cout << "List 1: ";
    print_list(l1);

    cout << "List 2: ";
    print_list(l2);

    // Merge the two lists
    node *merged_list = mergeLL(l1, l2);

    cout << "Merged List: ";
    print_list(merged_list);

    return 0;
}