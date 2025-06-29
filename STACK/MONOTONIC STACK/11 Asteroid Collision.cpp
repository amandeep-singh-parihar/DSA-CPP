#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

vector<int> asteroidCollision(vector<int> &nums)
{
    vector<int> ans;
    stack<int> st;
    int n = nums.size();
    for (int i = 0; i < n; ++i)
    {
        if (nums[i] > 0)
        {
            st.push(nums[i]);
        }
        else
        {
            while (!st.empty() && st.top() > 0 && st.top() < abs(nums[i]))
            {
                st.pop();
            }
            if (!st.empty() && st.top() == abs(nums[i]))
            {
                st.pop();
            }
            else if (st.empty() || st.top() < 0)
            {
                st.push(nums[i]);
            }
        }
    }

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

// second solution
vector<int> _asteroidCollision(vector<int> &nums)
{
    stack<int> st;
    vector<int> ans;
    int n = nums.size();
    for (int i = 0; i < n; ++i)
    {

        while (!st.empty() && nums[i] < 0 && st.top() > 0)
        {
            int sum = nums[i] + st.top();
            if (sum > 0)
            {
                nums[i] = 0;
                break;
            }
            else if (sum < 0)
            {
                st.pop();
            }
            else
            {
                nums[i] = 0;
                st.pop();
            }
        }

        if (nums[i] != 0)
        {
            st.push(nums[i]);
        }
    }

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<int> nums = {4, 7, 1, 1, 2, -3, -7, 17, 15, -16};
    vector<int> ans = asteroidCollision(nums);
    for (int it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}