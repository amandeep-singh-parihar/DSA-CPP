#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
//revision 1
void solve(vector<int>&arr,int sum,int& maxi,int i)
{
    if(i>=arr.size())
    {
        maxi=max(maxi,sum);
        return;
    }

    //exclude
    solve(arr,sum,maxi,i+1);

    //include
    solve(arr,sum+arr[i],maxi,i+2);
}
int main()
{
    vector<int>arr{2,1,4,9};
    int sum=0;
    int i=0;
    int maxi=INT_MIN;
    solve(arr,sum,maxi,i);
    cout<<maxi;

    return 0;
}