//1405. Longest Happy String
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

//revision needed very strongly

string longestDiverseString(int a, int b, int c)
{
    priority_queue<pair<int, char>, vector<pair<int, char>>> pq;
    if (a > 0)
    {
        pq.push({a, 'a'});
    }

    if (b > 0)
    {
        pq.push({b, 'b'});
    }

    if (c > 0)
    {
        pq.push({c, 'c'});
    }
    string res = "";
    while (!pq.empty())
    {
        int currCount = pq.top().first;
        int currChar = pq.top().second;
        pq.pop();

        if (res.length() >= 2 && res[res.length() - 1] == currChar && res[res.length() - 2] == currChar)
        {
            if (pq.empty())
            {
                break;
            }

            int nextCount = pq.top().first;
            int nextChar = pq.top().second;
            pq.pop();

            res.push_back(nextChar);
            --nextCount;
            if (nextCount > 0)
            {
                pq.push({nextCount, nextChar});
            }
        }
        else
        {
            --currCount;
            res.push_back(currChar);
        }

        if (currCount > 0)
        {
            pq.push({currCount, currChar});
        }
    }
    return res;
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << longestDiverseString(a, b, c);
    return 0;
}