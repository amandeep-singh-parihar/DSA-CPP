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
        return *max_element(n.begin(), n.end()) - '0';
    }

int main()
{
    vector<int> arr={1,2,3,4,5};
    int ans=*min_element(arr.begin(),arr.end());
    cout<<ans;

    return 0;
}