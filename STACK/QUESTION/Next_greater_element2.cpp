//a little complex to understand
#include <bits/stdc++.h>
using namespace std;

vector<int> NGE(vector<int> &arr, int size)
{
    stack<int> s;
    vector<int> ans(size, -1);

    for (int i = 0; i < size; ++i)
    {
        int current = arr[i];
        while (!s.empty() && arr[s.top()] < current)
        {
            ans[s.top()] = current;
            s.pop();
        }
        s.push(i);
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

    cout << "Next greater elements for each element in the array: ";
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
