#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

int minPartitions(string n)
{
    char maxi='0';
    for(auto i:n)
    {
        maxi=max(maxi,i);
    }
    return maxi-'0';
}

int main()
{
    string str;
    cin>>str;
    cout<<minPartitions(str);
    return 0;
}