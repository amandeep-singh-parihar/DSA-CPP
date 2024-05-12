#include <bits/stdc++.h>
#include <iterator>
using namespace std;

long long maximumHappinessSum(vector<int> &v, int k)
{
    sort(v.begin(), v.end(), greater<int>());

    long long temp = 0;
    for(int i=0;i<k;i++)
    {
        temp+=v[i];
    }
    return temp-(k-1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> v = {1,1,1,1};
    cout << maximumHappinessSum(v, 2);

    return 0;
}