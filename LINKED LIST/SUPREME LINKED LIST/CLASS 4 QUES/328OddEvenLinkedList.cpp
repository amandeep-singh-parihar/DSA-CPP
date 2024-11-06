// 328. Odd Even Linked List
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
//revision needed good pattern
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

node *oddEvenList(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *odd = head;
    node *even = head->next;
    node *temp = even;
    while (even != NULL && even->next != NULL)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = temp;

    return head;
}

int main()
{
    node *first = new node(1);
    node *second = new node(2);
    node *third = new node(3);
    node *four = new node(4);
    node *five = new node(5);
    first->next = second;
    second->next = third;
    third->next = four;
    four->next = five;
    print(first);

    node *ans = oddEvenList(first);
    print(ans);

    return 0;
}