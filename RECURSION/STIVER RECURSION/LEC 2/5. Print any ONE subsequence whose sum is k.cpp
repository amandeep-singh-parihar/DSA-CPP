// L7. All Kind of Patterns in Recursion | Print All | Print one | Count
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

bool printS(int i, vector<int> &ds, int s, int sum, vector<int> &arr)
{
    if (i == arr.size())
    {
        // condition satisfied
        if (s == sum)
        {
            for (auto it : ds)
                cout << it << " ";
            cout << endl;
            return true;
        }
        return false;
    }

    // include
    ds.push_back(arr[i]);
    s += arr[i];
    if (printS(i + 1, ds, s, sum, arr))
    {
        return true;
    };
    ds.pop_back();
    s -= arr[i];

    // exclude
    if (printS(i + 1, ds, s, sum, arr))
    {
        return true;
    };

    return false;
}

int main()
{
    vector<int> arr = {1, 2, 1};
    int sum = 2;
    vector<int> ds;
    printS(0, ds, 0, sum, arr);
    return 0;
}