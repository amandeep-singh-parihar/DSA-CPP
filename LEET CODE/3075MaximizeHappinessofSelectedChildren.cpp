#include <bits/stdc++.h>
using namespace std;

long long maximumHappinessSum(vector<int> &happiness, int k)
{
    sort(happiness.begin(),happiness.end());
    long long s=0;
    int ct=0;
    #pragma unroll
    for(int i=0;i<k;++i)
    {
        s+=max(happiness[i]-ct,0);
        ct++;
    }
    return s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int>happiness={12,1,42};
    int k=3;
    cout<<maximumHappinessSum(happiness,k);
    return 0;
}