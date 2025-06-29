// 19. Remove Nth Node From End of List
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

node *removeNthFromEnd(node *&head, int n)
{
    node *fast = head;
    for (int i = 0; i < n; ++i)
    {
        fast = fast->next;
    }
    if (fast == NULL)
    {
        return head->next;
    }
    node *slow = head;
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    node *deleteNode = slow->next;
    slow->next = slow->next->next;
    delete deleteNode;
    return head;
}

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

int main()
{
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    node *head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);

    // Print the original list
    cout << "Original List: ";
    print(head);

    // Specify the Nth node to remove from the end
    int n = 5;

    // Remove the Nth node from the end
    head = removeNthFromEnd(head, n);

    // Print the updated list after removing the Nth node
    cout << "Updated List: ";
    print(head);

    return 0;
}
