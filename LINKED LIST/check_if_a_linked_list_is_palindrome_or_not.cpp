#include <bits/stdc++.h>
using namespace std;

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

node *reversall(node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    node *prev = NULL;
    node *forward = NULL;
    node *current = head;
    while (current != NULL)
    {
        forward = current->next;
        current->next = prev;
        prev = current;
        current = forward;
    }
    return prev;
}

bool isPlaindrome(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return true;
    }
    node *slow = head;
    node *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = reversall(slow->next);
    slow = slow->next;
    while (slow != NULL)
    {
        if (head->data != slow->data)
        {
            return false;
        }
        head = head->next;
        slow = slow -> next;
    }
    return true;
}
int main() {
    node *head = new node(1); // Replace this with your own linked list creation logic
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(2);
    head->next->next->next->next = new node(1);

    bool isPalindrome = isPlaindrome(head);

    if (isPalindrome) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}
