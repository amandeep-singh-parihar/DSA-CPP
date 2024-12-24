// 496. Next Greater Element I
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &arr)
{
    stack<int> st;
    unordered_map<int, int> m;
    int n = arr.size();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() < arr[i])
            st.pop();
        if (st.empty())
            m[arr[i]] = -1;
        else
            m[arr[i]] = st.top();
        st.push(arr[i]);
    }
    vector<int> ans;
    for (int i = 0; i < nums1.size(); i++)
    {
        ans.push_back(m[nums1[i]]);
    }
    return ans;
}

int main()
{
    // Example inputs
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    // Compute Next Greater Elements
    vector<int> result = nextGreaterElement(nums1, nums2);

    // Output the results
    cout << "Next Greater Elements: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
