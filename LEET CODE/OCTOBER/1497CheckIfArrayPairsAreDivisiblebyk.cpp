//1497. Check If Array Pairs Are Divisible by k
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
//revision needed
bool canArrange(vector<int> &arr, int k)
{
    vector<int> mp(k, 0);
    for (int &num : arr)
    {
        int rem = (num % k + k) % k;
        mp[rem]++;
    }

    if (mp[0] % 2 != 0)
    {
        return false;
    }

    for (int rem = 1; rem <= k / 2; ++rem)
    {
        int counterHalf = k - rem;
        if (mp[counterHalf] != mp[rem])
        {
            return false;
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

    int k;
    cin >> k;

    cout << canArrange(arr, k);
    return 0;
}