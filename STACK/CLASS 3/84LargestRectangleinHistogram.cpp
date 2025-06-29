// 84. Largest Rectangle in Histogram
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// revision 2

vector<int> previousSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for (int i = 0; i < arr.size(); ++i)
    {
        while (s.top() != -1 && arr[i] <= arr[s.top()])
        {
            s.pop();
        }
        if (s.top() == -1)
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = s.top();
        }
        s.push(i);
    }
    return ans;
}

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for (int i = arr.size() - 1; i >= 0; --i)
    {
        while (s.top() != -1 && arr[i] <= arr[s.top()])
        {
            s.pop();
        }
        if (s.top() == -1)
        {
            // place the size of the array
            ans[i] = n;
        }
        else
        {
            ans[i] = s.top();
        }
        s.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int> &heights)
{
    if (heights.size() == 0)
    {
        return 0;
    }
    vector<int> pse = previousSmallerElement(heights, heights.size());
    vector<int> nse = nextSmallerElement(heights, heights.size());
    int maxi = 0;
    for (int i = 0; i < heights.size(); ++i)
    {
        maxi = max(maxi, heights[i] * (nse[i] - pse[i] - 1));
    }
    return maxi;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << largestRectangleArea(arr);
    cout << endl;
}