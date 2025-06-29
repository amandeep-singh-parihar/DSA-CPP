#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

vector<int>intersect(vector<int>& arr, vector<int>& brr)
{
    vector<int>res;
    int i=0,j=0;
    sort(arr.begin(),arr.end());
    sort(brr.begin(),brr.end());
    while(i<arr.size() && j<brr.size())
    {
        if(arr[i]>brr[j])
        {
            j++;
        }else if(arr[i]<brr[j])
        {
            i++;
        }else{
            res.push_back(arr[i]);
            ++i,++j;
        }
    }
    return res;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>arr(n);
    vector<int>brr(m);
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
    }
    for(int j=0;j<m;++j)
    {
        cin>>brr[j];
    }

    vector<int>ans=intersect(arr,brr);
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}