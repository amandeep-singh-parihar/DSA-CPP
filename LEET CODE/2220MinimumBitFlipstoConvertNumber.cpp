#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();


int minBitFlips(int start,int goal)
{
    int xorAns=start^goal;
    int res=0;
    while(xorAns>0)
    {
        res+=xorAns&1;
        xorAns>>=1;
    }
    return res;
}

int main()
{
    int start,goal;
    cin>>start>>goal;
    cout<<minBitFlips(start,goal);
    return 0;
}