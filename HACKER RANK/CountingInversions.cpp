#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

long countInversions(vector<int>& arr)
{
    int count=0;
    for(int i=0;i<arr.size();++i)
    {
        for(int j=i+1;j<arr.size();++j)
        {
            if(arr[i]>arr[j])
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
    }
    cout<<countInversions(arr);
    return 0;
}