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

ListNode *convert(vector<int> &arr)
{
    if (arr.empty())
    {
        return NULL;
    }
    ListNode *newHead = new ListNode(arr[0]);
    ListNode *temp = newHead;
    for (int i = 1; i < arr.size(); ++i)
    {
        ListNode *it = new ListNode(arr[i]);
        temp->next = it;
        temp = it;
    }
    return newHead;
}
ListNode *rotateRight(ListNode *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    ListNode *temp = head;
    vector<int> arr;
    while (temp)
    {
        arr.push_back(temp->val);
        temp = temp->next;
    }
    int n = arr.size();
    vector<int> brr(n);
    for (int i = 0; i < n; ++i)
    {
        brr[i] = arr[(i + n - (k % n)) % n];
    }
    return convert(brr);
}

int main() {
    // Create input vector for the linked list
    vector<int> input = {1, 2, 3, 4, 5};

    // Convert the input vector to a linked list
    ListNode* head = convert(input);

    // Rotate the linked list by k steps
    int k = 2; // Change this to test with different rotations
    ListNode* rotatedList = rotateRight(head, k);

    // Print the rotated linked list
    cout << "Rotated List: ";
    ListNode* temp = rotatedList;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
