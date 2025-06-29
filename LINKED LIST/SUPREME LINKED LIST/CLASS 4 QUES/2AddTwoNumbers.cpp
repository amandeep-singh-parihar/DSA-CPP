// 2. Add Two Numbers
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

node *addTwoNumbers(node *l1, node *l2)
{
    node *dummy = new node(0);
    node *temp = dummy;
    int carry = 0;
    while (l1 != NULL || l2 != NULL || carry)
    {
        int sum = 0;
        if (l1 != NULL)
        {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            sum += l2->data;
            l2 = l2->next;
        }
        sum += carry;
        carry = sum / 10;
        node *sumnode = new node(sum % 10);
        temp->next = sumnode;
        temp = temp->next;
    }
    return dummy->next;
}

int main()
{
    // Create first linked list: 2 -> 4 -> 3 -> NULL (represents the number 342)
    node *l1 = new node(2);
    l1->next = new node(4);
    l1->next->next = new node(3);

    // Create second linked list: 5 -> 6 -> 4 -> NULL (represents the number 465)
    node *l2 = new node(5);
    l2->next = new node(6);
    l2->next->next = new node(4);

    // Add the two numbers
    node *result = addTwoNumbers(l1, l2);

    cout << endl;
    print(l1);
    cout << endl;
    print(l2);
    cout << endl;

    // Print the result linked list: 7 -> 0 -> 8 -> NULL (represents the number 807)
    print(result);

    return 0;
}
