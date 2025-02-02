#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

bool lemonadeChange(vector<int> &arr)
{
    int five = 0, ten = 0;
    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] == 5)
        {
            ++five;
        }
        else if (arr[i] == 10)
        {
            if (five)
            {
                --five, ++ten;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if (five && ten)
            {
                --ten, --five;
            }
            else if (five >= 3)
            {
                five -= 3;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
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
    cout << lemonadeChange(arr);
    return 0;
}