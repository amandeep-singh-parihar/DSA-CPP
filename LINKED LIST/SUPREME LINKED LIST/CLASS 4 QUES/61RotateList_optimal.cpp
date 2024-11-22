// 61. Rotate List
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *findingTail(ListNode *head)
{
    ListNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    return temp;
}

int findingSize(ListNode *head)
{
    int c = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        c++;
    }
    return c;
}

ListNode *rotateRight(ListNode *head, int k)
{
    if (head == NULL)
        return NULL;
    int size = findingSize(head);
    k = k % size;
    if (k == 0)
        return head;
    ListNode *tail = findingTail(head);
    ListNode *temp = head;
    int j = findingSize(head) - k;
    for (int i = 0; i < j - 1; ++i)
    {
        temp = temp->next;
    }
    ListNode *newHead = temp->next;
    tail->next = head;
    temp->next = NULL;
    return newHead;
}

int main()
{
    // Helper function to create a linked list from a vector
    auto createList = [](const vector<int> &arr) -> ListNode *
    {
        if (arr.empty())
            return nullptr;
        ListNode *head = new ListNode(arr[0]);
        ListNode *temp = head;
        for (int i = 1; i < arr.size(); ++i)
        {
            temp->next = new ListNode(arr[i]);
            temp = temp->next;
        }
        return head;
    };

    // Helper function to print a linked list
    auto printList = [](ListNode *head)
    {
        while (head)
        {
            cout << head->val;
            if (head->next)
                cout << " -> ";
            head = head->next;
        }
        cout << endl;
    };

    // Create the linked list from a vector
    vector<int> arr = {1, 2, 3, 4, 5}; // Example list
    ListNode *head = createList(arr);

    cout << "Original List: ";
    printList(head);

    // Rotate the list
    int k = 2; // Example rotation count
    ListNode *rotatedHead = rotateRight(head, k);

    cout << "Rotated List: ";
    printList(rotatedHead);

    return 0;
}
