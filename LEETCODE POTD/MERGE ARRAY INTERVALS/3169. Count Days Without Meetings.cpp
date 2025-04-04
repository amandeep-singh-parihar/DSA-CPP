// 3169. Count Days Without Meetings
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Brute force
// TC O(n*n + days.size)
// SC O(days.size)
int countDays(int days, vector<vector<int>> &meetings)
{
    unordered_map<int, bool> total_days;
    for (auto &it : meetings)
    {
        for (long long j = it[0]; j <= it[1]; ++j)
        {
            total_days[j] = true;
        }
    }
    int cnt = 0;
    for (long long i = 1; i <= days; ++i)
    {
        if (total_days.find(i) == total_days.end())
        {
            ++cnt;
        }
    }
    return cnt;
}

// Optimal
// TC O(nlogn + n)
// SC O(1)
int countDays(int days, vector<vector<int>> &meetings)
{
    sort(meetings.begin(), meetings.end());
    int start = 0;
    int end = 0;
    int daysOff = 0;
    for (int i = 0; i < meetings.size(); ++i)
    {
        if (meetings[i][0] > end)
        {
            daysOff += meetings[i][0] - end - 1;
        }
        end = max(end, meetings[i][1]);
    }

    if (end < days)
    {
        daysOff += days - end;
    }
    return daysOff;
}

int main()
{

    return 0;
}