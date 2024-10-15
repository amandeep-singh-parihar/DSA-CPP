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
};

void insertATtail(node *&tail, node *&head, int d)
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
        tail->next = temp; // temp->next points tail(this is just a name it means it is pointing the data part of the list) to old LL
        tail = temp;       // now here the old tail become new tail(again this is a name for data) of the temp LL
    }
}

void insertAThead(node *&tail, node *&head, int d)
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
    node *nodeTOinsert = new node(d);
    if (position == 1)
    {
        insertAThead(tail, head, d);
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
        insertATtail(tail, head, d);
        return;
    }
    // creating a node for d
    //  node* nodeTOinsert=new node(d);
    nodeTOinsert->next = p->next;
    p->next = nodeTOinsert;
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
    // node *ll = new node(10);
    node *head = NULL;
    node *tail = NULL;

    insertATtail(tail, head, 20);
    print(head);
    insertATtail(tail, head, 30);
    print(head);
    insertATtail(tail, head, 40);
    print(head);
    insertATtail(tail, head, 50);
    print(head);

    insertATposition(tail, head, 1, 99);

    print(head);

    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;

    return 0;
}