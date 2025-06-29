//1942. The Number of the Smallest Unoccupied Chair
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
//brute force
int smallestChair(vector<vector<int>> &times, int targetFriend)
{
    int n = times.size();
    vector<int> chairs(n, -1);
    int arrival_time_of_target_friend = times[targetFriend][0];
    sort(times.begin(), times.end());
    for (vector<int> &time : times)
    {
        int arrival = time[0];
        int depart = time[1];
        for (int i = 0; i < n; ++i)
        {
            if (chairs[i] <= arrival)
            {
                chairs[i] = depart;
                if (arrival == arrival_time_of_target_friend)
                {
                    return i;
                }
                break;
            }
        }
    }
    return -1;
}

int main()
{
    int targetFriend;
    cin >> targetFriend;
    int rows;
    cin >> rows;
    vector<vector<int>> times(rows,vector<int>(2));
    for (int i = 0; i < rows; ++i)
    {
        cin>>times[i][0]>>times[i][1];
    }
    cout << smallestChair(times, targetFriend);
    return 0;
}