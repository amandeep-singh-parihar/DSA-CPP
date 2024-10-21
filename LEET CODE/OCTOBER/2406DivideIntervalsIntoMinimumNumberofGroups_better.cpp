//2406. Divide Intervals Into Minimum Number of Groups
#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

int minGroups(vector<vector<int>>&intervals)
{
    sort(intervals.begin(),intervals.end());
    priority_queue<int,vector<int>,greater<int>>pq;
    for(vector<int>interval : intervals)
    {
        int start=interval[0];
        int end=interval[1];
        if(!pq.empty() && start>pq.top())
        {
            pq.pop();
        }
        pq.push(end);
    }
    return pq.size();
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