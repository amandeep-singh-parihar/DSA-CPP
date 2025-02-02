// N meetings in one roomp
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

struct Data
{
    int start, end, pos;
};

static bool comp(Data a, Data b)
{
    return a.end < b.end;
}

int maxMeetings(vector<int> &start, vector<int> &end)
{
    int n = start.size();
    vector<Data> arr(n);
    for (int i = 0; i < n; ++i)
    {
        arr[i].start = start[i];
        arr[i].end = end[i];
        arr[i].pos = i;
    }
    sort(arr.begin(), arr.end(), comp);
    int cnt = 1;
    int freeTime = arr[0].end;
    vector<int> ds;
    ds.push_back(arr[0].pos);

    for (int i = 1; i < n; ++i)
    {
        if (arr[i].start > freeTime)
        {
            ++cnt;
            freeTime = arr[i].end;
            ds.push_back(arr[i].pos);
        }
    }
    return cnt;
}

int main()
{
    int n;
    cin >> n;
    vector<int> start(n);
    vector<int> end(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> start[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> end[i];
    }
    cout << maxMeetings(start, end);
    return 0;
}