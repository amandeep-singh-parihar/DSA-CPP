#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

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

void insert_at_head(node *&head, node *&tail, int d)
{

    if (head == NULL)
    {
        node *p = new node(d);
        head = p;
        tail = p;
    }

    node *p = new node(d);
    p->next = head;
    head = p;
}

void insert_at_tail(node *&head, node *&tail, int d)
{

    // if null
    if (tail == NULL)
    {
        node *p = new node(d);
        head = p;
        tail = p;
    }

    // at the end
    node *p = new node(d);
    tail->next = p;
    p = tail;
}

void insert_in_the_middle(node *&head, node *&tail, int d, int pos)
{

    if (head->next == NULL)
    {
        insert_at_head(head, tail, d);
    }

    if (tail == NULL)
    {
        insert_at_tail(head, tail, d);
    }

    // in the middle somewhere
    node *temphead = head;
    for (int i = 1; i < pos - 1; ++i)
    {
        temphead = temphead->next;
    }
    node *nodeToInsert = new node(d);
    nodeToInsert->next = temphead->next;
    temphead->next = nodeToInsert;
}

void delete_node(int pos, node *&head, node *&tail)
{
    if (pos == 1)
    {
        node *p = head;
        head = head->next;
        p->next = NULL;
        delete p;
        return;
    }

    node *current = head;
    node *prev = NULL;
    int cnt = 1;
    while (cnt < pos && current != NULL)
    {
        prev = current;
        current = current->next;
        // ++cnt;
        cnt++;
    }

    if (current == NULL)
        return;

    prev->next = current->next;
    current->next = NULL;
    delete current;

    if (prev->next == NULL)
    {
        tail = prev;
    }
}

node* reverse(node* &prev,node* &curr){
    if(curr== NULL) return prev;


    node* forward = curr->next;
    curr->next = prev;

    reverse(curr,prev);
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
    // node * tail = NULL;
    // sixt
    // insert_at_head(first,tail,-10000);
    // insert_at_tail(first, sixth, -1000);
    // insert_in_the_middle(first,sixth,-10000,3);
    delete_node(1,first,sixth);

    // print the ll
    node *p = first;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }

    return 0;
}