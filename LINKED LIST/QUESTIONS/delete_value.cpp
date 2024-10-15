#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    // constructor
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

void insertATtail(node *&tail, int d)
{
    node *p = new node(d);
    tail->next = p;
    tail = p;
}

void deleteNode(node *&head, node *&tail, int value)
{
    if (head->data == value) // position==1;
    {
        node *p = head;
        head = head->next;
        p->next = NULL;
        delete p;
        return;

        // if (head == nullptr) {
        //     tail = nullptr;
        // }
        // return;
    }

    node *current = head;
    node *previous = NULL;
    // int cnt = 1;
    while (current != NULL && current->data != value) // cnt<position && current!=NULL
    {
        previous = current;
        current = current->next;
        // cnt++;
        // previous=current;
        // current=current->next;
        // cnt++;
    }

    if (current == NULL)
    {
        cout << "postion is out of bounds " << endl;
        return;
    }

    previous->next = current->next;
    current->next = NULL;
    delete current;

    if (previous->next == NULL)
    {
        tail = previous;
        // return;
    }
}

int main()
{
    node *ll = new node(10);
    node *tail = ll;
    node *head = ll;

    insertATtail(tail, 30);
    insertATtail(tail, 40);
    insertATtail(tail, 50);
    insertATtail(tail, 70);

    print(head);

    // insertATposition(tail,head,2,20);
    // print(head);

    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;

    deleteNode(head, tail, 40);
    print(head);

    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;

    return 0;
}