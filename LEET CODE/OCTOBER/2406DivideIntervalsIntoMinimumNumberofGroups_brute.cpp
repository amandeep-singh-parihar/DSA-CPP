// 2406. Divide Intervals Into Minimum Number of Groups
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
// revisino needed
int minGroups(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<int> groups;
    for (vector<int> it : intervals)
    {
        int start = it[0];
        int end = it[1];
        bool placed = false;
        for (int &group_end : groups)
        {
            if (start > group_end)
            {
                group_end = end;
                placed = true;
                break;
            }
        }
        if (!placed)
        {
            groups.push_back(end);
        }
    }
    return groups.size();
}

int main()
{
    int rows;
    cin >> rows;
    vector<vector<int>> intervals(rows, vector<int>(2));
    for (int i = 0; i < rows; ++i)
    {
        cin >> intervals[i][0] >> intervals[i][1];
    }
    cout << minGroups(intervals);
    return 0;
}