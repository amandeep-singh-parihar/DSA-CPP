#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

int mincostTickets_helper(vector<int> &days, vector<int> &costs,int i)
{
    if(i>=days.size()) return 0;

    int cost1=costs[0]+mincostTickets_helper(days,costs,i+1);

    int passEndDay=days[i]+7-1;
    int j=i;
    while(j<days.size() && days[j]<=passEndDay)
    {
        j++;
    }
    int cost7=costs[1]+mincostTickets_helper(days,costs,j);

    passEndDay=days[i]+30-1;
    j=i;
    while (j<days.size() && days[j]<=passEndDay)
    {
        j++;
    }
    int cost30=costs[2]+mincostTickets_helper(days,costs,j);

    return min(cost1,min(cost7,cost30));
    
}

int mincostTickets(vector<int> &days, vector<int> &costs)
{
    return mincostTickets_helper(days, costs, 0);
}

int main()
{
    vector<int> days{1, 4, 6, 7, 8, 20};
    vector<int> costs{2, 7, 15};
    cout<<mincostTickets(days,costs);
    return 0;
}