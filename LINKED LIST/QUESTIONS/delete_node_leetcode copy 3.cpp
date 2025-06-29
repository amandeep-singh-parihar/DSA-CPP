/*There is a singly-linked list head and we want to delete a node node in it.

You are given the node to be deleted node. You will not be given access to the first node of head.

All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.

Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:

The value of the given node should not exist in the linked list.
The number of nodes in the linked list should decrease by one.
All the values before node should be in the same order.
All the values after node should be in the same order.*/

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

node* delete_the_node(node* &NODE)
{
    if(NODE->next==NULL)
    {
        cout<<"cannot delete last node. ";
    }else{
        NODE->data=NODE->next->data;
        NODE->next=NODE->next->next;
    }
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
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    
    // Print the original list
    cout << "Original List: ";
    print_list(head);

    // Delete the node with value 3 (for example)
    node* nodeToDelete = head->next->next; // Node with value 3
    delete_the_node(nodeToDelete);

    // Print the updated list
    cout << "Updated List: ";
    print_list(head);

    return 0;
}