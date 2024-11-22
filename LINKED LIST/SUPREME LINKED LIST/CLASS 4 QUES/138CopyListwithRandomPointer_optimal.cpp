// 138. Copy List with Random Pointer
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *copyRandomList(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    // step1
    Node *it = head;
    while (it)
    {
        Node *clonedNode = new Node(it->val);
        clonedNode->next = it->next;
        it->next = clonedNode;
        it = it->next->next;
    }

    // step2
    it = head;
    while (it)
    {
        Node *clonedNode = it->next;
        clonedNode->random = it->next ? it->random->next : NULL;
        it = it->next->next;
    }

    // step3
    it = head;
    Node *clonedHead = it->next;
    while (it)
    {
        Node *clonedNode = it->next;
        it->next = it->next->next;
        if (clonedNode->next)
        {
            clonedNode->next = clonedNode->next->next;
        }
        it = it->next;
    }
    return clonedHead;
}

int main()
{
    // Create a linked list with random pointers
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);

    head->next = second;
    second->next = third;

    // Set up random pointers
    head->random = third;   // 1 -> 3
    second->random = head;  // 2 -> 1
    third->random = second; // 3 -> 2

    // Call the function to copy the list
    Node *copiedList = copyRandomList(head);

    // Print the original and copied lists to verify
    cout << "Original list:" << endl;
    Node *temp = head;
    while (temp)
    {
        cout << "Node value: " << temp->val;
        if (temp->random)
        {
            cout << ", Random points to: " << temp->random->val << endl;
        }
        else
        {
            cout << ", Random points to: NULL" << endl;
        }
        temp = temp->next;
    }

    cout << "\nCopied list:" << endl;
    temp = copiedList;
    while (temp)
    {
        cout << "Node value: " << temp->val;
        if (temp->random)
        {
            cout << ", Random points to: " << temp->random->val << endl;
        }
        else
        {
            cout << ", Random points to: NULL" << endl;
        }
        temp = temp->next;
    }

    return 0;
}
