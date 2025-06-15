// sort 0's 1's 2's in Linked List
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// revision 2

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
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *zerohead = new node(-1);
    node *zero = zerohead;
    node *onehead = new node(-1);
    node *one = onehead;
    node *twohead = new node(-1);
    node *two = twohead;
    node *temp = head;
    while (temp) // temp != NULL
    {
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = zero->next;
        }
        else if (temp->data == 1)
        {
            one->next = temp;
            one = one->next;
        }
        else
        {
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }

    zero->next = (onehead->next) ? (onehead->next) : (twohead->next);
    one->next = twohead->next;
    two->next = NULL;
    node *newHead = zerohead->next;
    delete zerohead;
    delete onehead;
    delete twohead;
    return newHead;
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