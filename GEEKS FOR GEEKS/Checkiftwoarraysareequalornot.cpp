#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool check(vector<ll> A, vector<ll> B, int N)
{
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int i = 0;
    while (i < N)
    {
        if (A[i] != B[i])
        {
            return false;
        }
        i++;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<ll> arr(n, 0), brr(n, 0);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (ll i = 0; i < n; i++)
        {
            cin >> brr[i];
        }
        int ans=check(arr,brr,n);
        cout<<ans<<"\n";
    }
    return 0;
}