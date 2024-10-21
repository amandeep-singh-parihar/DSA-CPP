// 25. Reverse Nodes in k-Group
//VERY IMPORTANT QUESTION
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

int getLength(node *&head)
{
    int c = 0;
    node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        c++;
    }
    return c;
}

node *reverseKGroup(node *&head, int k)
{
    if (head == NULL || getLength(head) < k)
    {
        return head;
    }

    int count = 0;
    node *prev = NULL;
    node *curr = head;
    node *forward = NULL;
    while (count < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }
    if (forward != NULL)
    {
        head->next = reverseKGroup(forward, k);
    }
    return prev;
}

void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    node *head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);

    print(head);
    cout << endl;

    node *ans = reverseKGroup(head, 3);
    print(ans);

    return 0;
}