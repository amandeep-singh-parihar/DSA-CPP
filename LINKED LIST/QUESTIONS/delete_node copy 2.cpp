#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    // constuctor
    node(int data)
    {
        this->data = data;
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
        node *p = new node(d);
        tail->next = p;
        tail = p;
    }
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
        node *p = new node(d);
        p->next = head;
        head = p;
    }
}

void insertATposition(node *&tail, node *&head, int position, int d)
{
    // insert at head
    if (position == 1)
    {
        insertAThead(head, tail, d);
        return;
    }
    node *p = head;
    if (p->next == NULL)
    {
        insertATtail(head, tail, d);
        return;
    }

    int cnt = 1;
    while (cnt < position - 1)
    {
        p = p->next;
        cnt++;
    }

    node *insertHONEwalinode = new node(d);

    insertHONEwalinode->next = p->next;
    p->next = insertHONEwalinode;
}

void deleteNode(int position, node *&head, node *&tail)
{
    if (position == 1)
    {
        node *p = head;
        head = head->next;
        p->next = NULL;
        delete p;
        return;
    }
    else
    {

        node *current = head;
        node *previous = NULL;
        int cnt = 1;
        while (cnt < position && current != NULL) //
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

        previous->next = current->next;
        current->next = NULL;
        delete current;

        if (previous->next == NULL)
        {
            tail = previous;
        }
    }
}

void print(node *&head)
{
    node *p = head;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    node *ll = new node(10);
    node *tail = ll;
    node *head = ll;

    insertATtail(head, tail, 30);
    insertATtail(head, tail, 40);
    insertATtail(head, tail, 50);

    print(head);

    insertATposition(tail, head, 2, 20);
    print(head);

    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;

    deleteNode(3, head, tail);
    print(head);

    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;

    return 0;
}