#include <bits/stdc++.h>
using namespace std;

vector<int> NGE(vector<int> &arr, int size)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(size);

    for (int i = size - 1; i >= 0; --i)
    {
        //-a+     summary
        int current = arr[i];
        while (!s.empty() && current >= s.top())
        {
            s.pop();
        }

        if (s.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = s.top();
        }
        s.push(current);
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> result = NGE(arr, n);

    cout << "Next Greater elements for each element in the array: ";
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}