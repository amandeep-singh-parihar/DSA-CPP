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

void INSERT_AT_ANY_POSITION(node *&head, node *&tail, int index, int data)
{
    node *nodeToInsert = new node(data);
    if (index == 0)
    {
        nodeToInsert->next = head;
        head = nodeToInsert;
        return;
    }

    node *p = head;
    int cnt = 1;
    while (cnt < index)
    {
        p = p->next;
        cnt++;
    }

    if (p->next == nullptr)
    {
        tail->next = nodeToInsert;
        tail = nodeToInsert;
        return;
    }
    nodeToInsert->next = p->next;
    p->next = nodeToInsert;
}

void print(node *&head)
{
    node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp=temp->next;
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

    INSERT_AT_ANY_POSITION(first,sixth,6,9000);
    print(first);
    return 0;
}