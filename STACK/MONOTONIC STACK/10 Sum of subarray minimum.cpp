#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Brute Force
// TC O(N^2)
// SC O(1)
#define ll long long
#define MOD int(1e9 + 7)

int findMin(vector<int> &arr)
{
    int mini = INT_MAX;
    for (int i = 0; i < arr.size(); ++i)
    {
        mini = min(mini, arr[i]);
    }
    return mini;
}

int sumSubarrayMins(vector<int> &arr)
{
    ll sum = 0;
    int n = arr.size();

    for (int i = 0; i < n; ++i)
    {
        vector<int> subarray;
        for (int j = i; j < n; ++j)
        {
            subarray.push_back(arr[j]);
            sum = (sum + findMin(subarray)) % MOD;
        }
    }

    return static_cast<int>(sum);
}

// TC O(5N)
// SC O(5N)
vector<int> nse(vector<int> &arr)
{
    stack<int> st;
    int n = arr.size();
    vector<int> NSE(n);
    for (int i = n - 1; i >= 0; --i)
    {

        while (!st.empty() && arr[st.top()] > arr[i])
        {
            st.pop();
        }

        if (!st.empty())
        {
            NSE[i] = st.top();
        }
        else if (st.empty())
        {
            NSE[i] = n;
        }
        st.push(i);
    }
    return NSE;
}
vector<int> psee(vector<int> &arr)
{
    stack<int> st;
    int n = arr.size();
    vector<int> PSEE(n);
    for (int i = 0; i < n; ++i)
    {

        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            PSEE[i] = -1;
        }
        else
        {
            PSEE[i] = st.top();
        }
        st.push(i);
    }
    return PSEE;
}
int sumSubarrayMins(vector<int> &arr)
{
    int n = arr.size();
    vector<int> NSE = nse(arr);
    vector<int> PSEE = psee(arr);
    int total = 0;
    int mod = (int)(1e9 + 7);
    for (int i = 0; i < n; ++i)
    {
        int left = i - PSEE[i];
        int right = NSE[i] - i;
        total = (total + (right * left * 1LL * arr[i]) % mod) % mod;
    }
    return total;
}

int main()
{
    vector<int> arr = {3, 1, 2, 4};
    cout << sumSubarrayMins(arr);
    return 0;
}