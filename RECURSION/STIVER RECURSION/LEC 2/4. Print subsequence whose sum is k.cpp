// L7. All Kind of Patterns in Recursion | Print All | Print one | Count
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

void printS(int i, vector<int> &ds, int s, int sum, vector<int> &arr)
{
    if (i == arr.size())
    {
        if (s == sum)
        {
            for (auto it : ds)
                cout << it << " ";
            cout << endl;
        }
        return;
    }

    // include
    ds.push_back(arr[i]);
    s += arr[i];
    printS(i + 1, ds, s, sum, arr);
    ds.pop_back();
    s -= arr[i];

    // exclude
    printS(i + 1, ds, s, sum, arr);
}

int main()
{
    vector<int> arr = {1, 2, 1};
    int sum = 2;
    vector<int> ds;
    printS(0, ds, 0, sum, arr);
    return 0;
}