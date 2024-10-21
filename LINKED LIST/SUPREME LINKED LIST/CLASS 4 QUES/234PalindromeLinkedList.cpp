// 234. Palindrome Linked List
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

node *reveseLinkedList(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *prev = NULL;
    node *curr = head;
    node *forward = NULL;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

bool isPalindrome(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return true;
    }

    node *slow = head;
    node *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    slow->next = reveseLinkedList(slow->next);
    slow = slow->next;
    while (slow != NULL)
    {
        if (head->data != slow->data)
        {
            return false;
        }
        head = head->next;
        slow = slow->next;
    }
    return true;
}

void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // Creating a linked list with nodes
    node *head = new node(10);
    node *second = new node(20);
    node *third = new node(30);
    node *fourth = new node(40);
    node *fifth = new node(50);
    node *sixth = new node(40);
    node *seventh = new node(30);
    node *eight = new node(20);
    node *ninth = new node(10);

    // Connecting the nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eight;
    eight->next = ninth;
    cout << endl;
    print(head);
    cout<<endl;
    if(isPalindrome(head))
    {
        cout<<"The Given Linked List is Palindrome"<<endl;
    }else{
        cout<<"The Given Linked List is (NOT) Palindrome"<<endl;
    }
    cout<<endl;
    return 0;
}