#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

//revision 1

vector<int> previousSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

#pragma unroll
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

#pragma unroll
    for (int i = arr.size() - 1; i >= 0; --i)
    {
        while (s.top() != -1 && arr[i] <= arr[s.top()])
        {
            s.pop();
        }
        if (s.top() == -1)
        {
            ans[i] = n; // Place the size of the array
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

#pragma unroll
    for (int i = 0; i < heights.size(); ++i)
    {
        maxi = max(maxi, heights[i] * (nse[i] - pse[i] - 1));
    }
    return maxi;
}

int maximalRectangle(vector<vector<char>> &matrix)
{
    vector<vector<int>> v;
    int n = matrix.size();
    int m = matrix[0].size();

#pragma unroll
    for (int i = 0; i < n; ++i)
    {
        vector<int> t;

#pragma unroll
        for (int j = 0; j < m; ++j)
        {
            t.push_back(matrix[i][j] - '0');
        }
        v.push_back(t);
    }

    int area = largestRectangleArea(v[0]);

#pragma unroll
    for (int i = 1; i < n; ++i)
    {
#pragma unroll
        for (int j = 0; j < m; ++j)
        {
            if (v[i][j])
            {
                v[i][j] += v[i - 1][j];
            }
            else
            {
                v[i][j] = 0;
            }
        }
        area = max(area, largestRectangleArea(v[i]));
    }
    return area;
}

int main(){
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    int maxArea = maximalRectangle(matrix);
    cout << "Maximum rectangle area: " << maxArea << endl;
    return 0;
}
