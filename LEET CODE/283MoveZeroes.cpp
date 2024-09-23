#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

void moveZeroes(vector<int>& arr)
{
    int j=0;
    for(int i=0;i<arr.size();++i)
    {
        if(arr[i]!=0)
        {
            swap(arr[i],arr[j]);
            ++j;
        }
    }
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
    moveZeroes(arr);
    for(int i=0;i<n;++i)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}