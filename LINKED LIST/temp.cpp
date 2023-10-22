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

node* kReverse(node* &head,int k)
{
    if(head==NULL)
    {
        return NULL;
    }

    node* forward=NULL;
    node* current=head;
    node* previous=NULL;
    int c=0;
    while(current!=NULL && c<k)
    {
        forward=current->next;
        current->next=previous;
        previous=current;
        current=forward;
        c++;
    }

    if(forward!=NULL)
    {
        head->next=kReverse(forward,k);
    }

    return previous;
}

int main()
{
    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    node* head = NULL; // Initialize the head of the linked list to NULL

    // Code to create the linked list with some nodes
    int n; // Number of nodes in the linked list
    cout << "Enter the number of nodes: ";
    cin >> n;
    
    cout << "Enter the values of nodes: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        if (head == NULL) {
            head = new node(val);
        } else {
            node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new node(val);
        }
    }

    // Call the kReverse function to reverse k nodes at a time
    head = kReverse(head, k);

    // Print the reversed linked list
    node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}
