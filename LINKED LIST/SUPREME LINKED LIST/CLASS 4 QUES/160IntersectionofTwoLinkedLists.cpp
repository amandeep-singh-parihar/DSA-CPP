// 160. Intersection of Two Linked Lists
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

node *getIntersectionNode(node *&headA, node *&headB)
{
    if (headA == NULL || headB == NULL)
        return NULL;
    node *d1 = headA;
    node *d2 = headB;
    while (d1 != d2)
    {
        d1 = d1 == NULL ? headB : d1 = d1->next;
        d2 = d2 == NULL ? headA : d2 = d2->next;
    }
    return d1;
}

int main()
{
    // Creating two linked lists
    // List A: 1 -> 9 -> 1 -> 2 -> 4
    node *headA = new node(1);
    headA->next = new node(9);
    headA->next->next = new node(1);

    // List B: 3 -> 2 -> 4 (intersection starts at node 2)
    node *headB = new node(3);

    // Common part: 2 -> 4
    node *common = new node(2);
    common->next = new node(4);

    // Attaching the common part to both lists
    headA->next->next->next = common; // 1 -> 9 -> 1 -> 2 -> 4
    headB->next = common;             // 3 -> 2 -> 4

    // Print both lists
    cout << "List A: ";
    print(headA);

    cout << "List B: ";
    print(headB);

    // Finding the intersection node
    node *intersection = getIntersectionNode(headA, headB);

    if (intersection != NULL)
    {
        cout << "Intersection at node with data: " << intersection->data << endl;
    }
    else
    {
        cout << "No intersection found." << endl;
    }

    return 0;
}
