// 21. Merge Two Sorted Lists
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

node *mergeTwoLists(node *l1, node *l2)
{
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    if (l1->data > l2->data)
    {
        swap(l1, l2);
    }
    node *res = l1; // points to smaller
    while (l1 != NULL && l2 != NULL)
    {
        node *temp = NULL;
        while (l1 != NULL && l1->data <= l2->data)
        {
            temp = l1;
            l1 = l1->next;
        }
        temp->next = l2;
        swap(l1, l2);
    }
    return res;
}

int main()
{
    // Creating first sorted linked list: 1 -> 3 -> 5 -> NULL
    node *l1 = new node(1);
    l1->next = new node(3);
    l1->next->next = new node(5);

    // Creating second sorted linked list: 2 -> 4 -> 6 -> NULL
    node *l2 = new node(2);
    l2->next = new node(4);
    l2->next->next = new node(6);

    // Printing both lists before merge
    cout << "List 1: ";
    print(l1);
    cout << "List 2: ";
    print(l2);

    // Merging the two sorted lists
    node *mergedList = mergeTwoLists(l1, l2);

    // Printing the merged list
    cout << "Merged List: ";
    print(mergedList);

    return 0;
}
