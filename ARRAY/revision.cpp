#include <bits/stdc++.h>
using namespace std;


int solve(vector<int>&arr,vector<int>&brr)
{
    int n=arr.size();
    int count=0;
    unordered_set<int>elem_in_br(brr.begin(),brr.end());
    for(int i=0;i<n;++i)
    {
        if(elem_in_br.find(arr[i])!=elem_in_br.end())
        {
            count++;
        }
    }
    return count;
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>arr(n) ;
        vector<int>brr(n);
        for(int i=0;i<n;++i)
        {
            cin>>arr[i];
        }
        for(int j=0;j<n;++j)
        {
            cin>>brr[j];
        }
        cout<<solve(arr,brr)<<endl;
    }
}
