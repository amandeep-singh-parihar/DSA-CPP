// 503. Next Greater Element II
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// revision needed

vector<int> nextGreaterElements(vector<int> &nums)
{
    stack<int> s;
    s.push(-1);
    int n = nums.size();
    vector<int> ans(n);
    for (int i = 2 * n - 1; i >= 0; --i)
    {
        while (!s.empty() && nums[i % n] >= s.top())
        {
            s.pop();
        }
        if (s.empty())
        {
            ans[i % n] = -1;
        }
        else
        {
            ans[i % n] = s.top();
        }
        s.push(nums[i % n]);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n; // Input the size of the array

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i]; // Input the elements of the array
    }

    vector<int> result = nextGreaterElements(nums);

    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " "; // Output the next greater elements
    }
    cout << endl;

    return 0;
}