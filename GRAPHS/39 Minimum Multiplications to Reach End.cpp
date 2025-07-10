// Minimum Multiplications to reach End GFG
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// TC O(1e5*N) N->arr.size()
// SC O(1e9 + q.size())
// Each number (from 0 to 99999) is considered a node.
// An edge exists from u to v if v = (u * arr[i]) % 100000.
int minimumMultiplications(vector<int> &arr, int start, int end)
{
    if (start == end)
        return 0;
    queue<pair<int, int>> q;
    q.push({start, 0});
    vector<int> dist(1e5, 1e9);
    dist[start] = 0;
    int mod = 1e5;
    while (!q.empty())
    {
        int node = q.front().first;
        int steps = q.front().second;
        q.pop();

        for (auto it : arr)
        {
            int num = (1LL * it * node) % mod;
            if (steps + 1 < dist[num])
            {
                dist[num] = steps + 1;
                if (num == end)
                    return steps + 1;
                q.push({num, steps + 1});
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {2, 5, 7}; // Multiplication options
    int start = 3;               // Starting number
    int end = 30;                // Target number

    cout << "Minimum multiplications to reach " << end << " from " << start << " is: ";
    cout << minimumMultiplications(arr, start, end) << endl;

    return 0;
}
