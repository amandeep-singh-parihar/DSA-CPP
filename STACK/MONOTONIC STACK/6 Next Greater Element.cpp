#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Brute
// TC O(N^2)
// Sc O(N)
vector<int> NGE2(vector<int> &nums)
{
    int n = nums.size();
    vector<int> nge2(n, -1);

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j <= i + n - 1; ++j)
        {
            int idx = j % n;
            if (nums[idx] > nums[i])
            {
                nge2[i] = nums[idx];
                break;
            }
        }
    }

    return nge2;
}

// better
// TC O(2N + 2N)
// SC O(2N)

vector<int> _NGE2(vector<int> &nums)
{
    int n = nums.size();
    vector<int> nge2(n, -1);

    stack<int> st;
    // first to to fill the stack from the hypothetical array
    for (int i = n - 1; i >= 0; --i)
    {
        while (!st.empty() && st.top() <= nums[i])
        {
            st.pop();
        }
        st.push(nums[i]);
    }

    // second round
    for (int i = n - 1; i >= 0; --i)
    {
        while (!st.empty() && st.top() <= nums[i])
        {
            st.pop();
        }

        if (!st.empty() && st.top() > nums[i])
        {
            nge2[i] = st.top();
        }
        else if (st.empty())
        {
            nge2[i] = -1;
        }
        st.push(nums[i]);
    }
    return nge2;
}

// optimal
// TC O(4N)
// Sc O(2N) + O(N)
vector<int> __NGE2(vector<int> &nums)
{
    int n = nums.size();
    vector<int> nge2(n, -1);

    stack<int> st;
    for (int i = 2 * n - 1; i >= 0; --i)
    {
        while (!st.empty() && st.top() <= nums[i % n])
        {
            st.pop();
        }

        if(i<n){
            nge2[i] = st.empty() ? -1 : st.top();
        }

        st.push(nums[i%n]);
    }
    return nge2;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 3};
    vector<int> ans = __NGE2(nums);
    for (int it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}