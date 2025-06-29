#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// revision 1

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

    node()
    {
        this->data = 0;
        this->next = NULL;
    }
};

void INSERT_AT_HEAD(node *&head, node *&tail, int d)
{
    if (head == nullptr)
    {
        node *newNode = new node(d);
        head = newNode;
        tail = newNode;
    }

    node *p = new node(d);
    p->next = head;
    head = p;
}

void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    node *first = new node(10);
    node *second = new node(20);
    node *third = new node(30);
    node *fourth = new node(40);
    node *fifth = new node(50);
    node *sixth = new node(60);
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    node *tail = nullptr;
    INSERT_AT_HEAD(first, tail, -9100);
    print(first);
    return 0;
}