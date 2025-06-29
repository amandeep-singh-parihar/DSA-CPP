#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *prev;
    node *next;

    // constructor
    node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    // destructor
    ~node()
    {
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};

void print(node *&head)
{
    node *p = head;
    while (p != NULL)
    {
        cout << p->data << " "; //->
        p = p->next;
    }
    // cout<<"NULL";
    cout << endl;
}

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

void insertAThead(node *&head, node *&tail, int d)
{
    if (head == NULL)
    {
        node *temp = new node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        node *temp = new node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertATtail(node *&head, node *&tail, int d)
{
    if (tail == NULL)
    {
        node *temp = new node(d);
        tail = temp;
        head = temp;
    }
    else
    {
        node *temp = new node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertATANYposition(node *&tail, node *&head, int position, int d)
{
    node *nodeTOinsert = new node(d);
    if (position == 1)
    {
        insertAThead(head, tail, d);
        return;
    }
    node *p = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        p = p->next;
        cnt++;
    }

    if (p->next == NULL)
    {
        insertATtail(tail, tail, d);
        return;
    }
    // creating a node for d
    //  node* nodeTOinsert=new node(d);
    nodeTOinsert->next = p->next;
    p->next->prev = nodeTOinsert;
    p->next = nodeTOinsert;
    nodeTOinsert->prev = p;
}

void deleteNODE(node *&head, node *&tail, int position)
{
    if (position == 1)
    {
        node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    else
    {

        node *current = head;
        node *previous = NULL;
        int cnt = 1;
        while (cnt < position && current != NULL)
        {
            previous = current;
            current = current->next;
            cnt++;
        }

        if (current == NULL)
        {
            cout << "Position is out of bounds." << endl;
            return;
        }

        current->prev = NULL;
        previous->next = current->next;
        if(current->next!=NULL)
        {
            current->next->prev=previous;
        }
        current->next = NULL;
        delete current;

        if (previous->next == NULL)
        {
            tail = previous;
        }
    }
}

int main()
{
    node* what=new node(10);
    node* head=what;
    node* tail=what;
    insertATtail(head,tail,20);
    insertATtail(head,tail,30);
    insertATtail(head,tail,40);
    insertATtail(head,tail,50);
    insertATtail(head,tail,60);
    // insertATtail(head,tail,70);
    // insertATtail(head,tail,80);
    // insertATtail(head,tail,90);

    print(head);

    insertATANYposition(tail,head,1,99999);
    print(head);

    deleteNODE(head,tail,7);
    print(head);

    // cout << "head " << head->data << endl;
    // cout << "tail " << tail->data << endl;

    return 0;
}