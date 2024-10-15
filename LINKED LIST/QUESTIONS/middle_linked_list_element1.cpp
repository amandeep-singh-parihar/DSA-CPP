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

int getLength(node *head)
{
    int len = 0;
    node *p = head;
    while (p != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}

node* findmiddle(node* &head)
{
    int len=getLength(head);
    int ans=(len/2);

    node* temp=head;
    while(ans--)
    {
        temp=temp->next;
    }
    return temp;
}
int main()
{
    // Create a linked list with some nodes
    node *head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    // head->next->next->next->next = new node(5);

    // Find the middle node of the linked list
    node *middle = findmiddle(head);

    // Print the data of the middle node
    cout << "The middle node data is: " << middle->data << endl;

    // Don't forget to deallocate memory to avoid memory leaks
    while (head != nullptr)
    {
        node *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
