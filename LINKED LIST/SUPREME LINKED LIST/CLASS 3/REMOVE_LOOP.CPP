// VERY IMPORTANT QUES
#include <bits/stdc++.h>
using namespace std;
// REVISION 1
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

// Function to print the linked list
void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to detect and remove the cycle from the linked list
void removeCycle(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }

    node *fast = head;
    node *slow = head;
    node *entry = head;

    // Detect the cycle using Floyd's Cycle Detection Algorithm
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        // If fast and slow pointers meet, there is a cycle
        if (fast == slow)
        {
            // node *entry = head;
            node *prev = NULL;

            // Find the entry point of the cycle
            while (entry != slow)
            {
                prev = slow;
                entry = entry->next;
                slow = slow->next;
            }

            // `prev` now points to the last node in the cycle
            // Break the cycle by setting the next pointer of the last node to NULL
            if (prev != NULL)
            {
                prev->next = NULL;
            }
            return;
        }
    }
}

int main()
{
    // Creating a linked list with nodes
    node *head = new node(10);
    node *second = new node(20);
    node *third = new node(30);
    node *fourth = new node(40);
    node *fifth = new node(50);
    node *sixth = new node(60);
    node *seventh = new node(70);
    node *eight = new node(80);
    node *ninth = new node(90);

    // Connecting the nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eight;
    eight->next = ninth;
    ninth->next = fifth; // loop

    // Remove the cycle if it exists
    removeCycle(head);

    // Print the list after removing the cycle
    print(head);

    return 0;
}
