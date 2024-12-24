// 1019. Next Greater Node In Linked List
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

vector<int>convert(ListNode* head)
{
    vector<int>ans;
    ListNode* temp=head;
    while(temp)
    {
        ans.push_back(temp->val);
        temp=temp->next;
    }
    return ans;
}

vector<int>NGE(vector<int>arr)
{
    vector<int>ans(arr.size());
    stack<int>s;
    s.push(-1);
    for(int i=arr.size()-1;i>=0;--i)
    {
        while(!s.empty() && arr[i]>=s.top())
        {
            s.pop();
        }
        if(s.empty())
        {
            ans[i]=0;
        }else{
            ans[i]=s.top();
        }
        s.push(arr[i]);
    }
    return ans;
}

vector<int> nextLargerNodes(ListNode *head)
{
    vector<int> res = NGE(convert(head));
    return res;
}

int main() {
    // Creating a linked list: 2 -> 1 -> 5
    ListNode* head = new ListNode(2);
    head->next = new ListNode(1);
    head->next->next = new ListNode(5);

    // Call the function
    vector<int> result = nextLargerNodes(head);

    // Print the results
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Free allocated memory
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
