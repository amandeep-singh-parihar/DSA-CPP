//228. Summary Ranges
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

//revision 1

vector<string> summaryRanges(vector<int> &arr)
{
    vector<string> res;
    for (int i = 0; i < arr.size(); ++i)
    {
        int start = arr[i];
        while (i + 1 < arr.size() && arr[i] + 1 == arr[i + 1])
        {
            i++;
        }
        if (start == arr[i])
        {
            res.push_back(to_string(start));
        }
        else
        {
            res.push_back(to_string(start) + "->" + to_string(arr[i]));
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    vector<string> ans = summaryRanges(arr);
    for (const auto &it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}