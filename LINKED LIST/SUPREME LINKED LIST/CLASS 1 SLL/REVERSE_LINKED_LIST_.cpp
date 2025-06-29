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

// revision 1

node *reversll(node *&head)
{
    // head==null matlab ek he kuch ha he ne
    // head->next==null matlab ek he node h to wo phle se he reversed h
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *prev = NULL;
    node *forward = NULL;
    node *current = head;
    while (current != NULL)
    {
        forward = current->next;
        current->next = prev;
        prev = current;
        current = forward;
    }

    return prev;
}

void print(node *head)
{
    node *p = head;
    while (p != NULL)
    {
        cout << p->data << " -> ";
        p = p->next;
    }
    cout << "NULL";
    cout << endl;
}

int main()
{
    node *ll = new node(10);
    ll->next = new node(20);
    ll->next->next = new node(30);
    ll->next->next->next = new node(40);

    cout << "Original linked list : ";
    print(ll);

    ll = reversll(ll);

    cout << "Reversed linked list : ";
    print(ll);
    return 0;
}