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
        this->next = nullptr;
    }

    node()
    {
        this->data = 0;
        this->next = nullptr;
    }
};

void INSERT_AT_TAIL(node *&head, node *&tail, int d)
{
    if (tail == nullptr)
    {
        tail = new node(d);
        head = tail;
        return;
    }
    // other wise insert at the tail
    node *p = new node(d);
    tail->next = p;
    tail = p;
}

void print(node *&head)
{
    node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    // node *first = new node(10);
    // node *second = new node(20);
    // node *third = new node(30);
    // node *fourth = new node(40);
    // node *fifth = new node(50);
    // node *sixth = new node(60);
    // first->next = second;
    // second->next = third;
    // third->next = fourth;
    // fourth->next = fifth;
    // fifth->next = sixth;
    node *head = nullptr;
    node *tail = nullptr;
    INSERT_AT_TAIL(head, tail, 1500);
    print(head);
    return 0;
}