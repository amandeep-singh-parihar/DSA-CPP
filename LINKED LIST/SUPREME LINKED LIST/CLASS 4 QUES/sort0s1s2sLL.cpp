// sort 0's 1's 2's in Linked List
// T.C(n)
// S.C(1)
// This may be not accepeted by the interviewer as he can throw the next question like solve
// without replacing the data
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
};

void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

node *sort012(node *&head)
{
    int zero = 0;
    int one = 0;
    int two = 0;
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            ++zero;
        }
        else if (temp->data == 1)
        {
            ++one;
        }
        else
        {
            ++two;
        }
        temp = temp->next;
    }

    node *p = head;
    while (p != NULL)
    {
        while (zero--)
        {
            p->data = 0;
            p = p->next;
        }
        while (one--)
        {
            p->data = 1;
            p = p->next;
        }
        while (two--)
        {
            p->data = 2;
            p = p->next;
        }
    }
    return head;
}

int main()
{
    // Creating a linked list with some duplicates
    node *head = new node(1);
    node *second = new node(2);
    node *third = new node(0); // duplicate
    node *fourth = new node(2);
    node *fifth = new node(0);
    node *sixth = new node(2); // duplicate
    node *seventh = new node(1);
    node *eight = new node(2);
    node *ninth = new node(1);

    // Linking the nodes together
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eight;
    eight->next = ninth;

    cout << endl;
    print(head); // Print original list
    cout << endl;

    node *ans = sort012(head);
    print(ans);
    cout << endl;

    return 0;
}