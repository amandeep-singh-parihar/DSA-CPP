#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
//revision 1
int solve(int n,int x,int y,int z)
{
    //base case
    if(n==0)
    {
        return 0;
    }

    //base case 2
    if(n<0)
    {
        return INT_MIN;
    }

    //R call
    int ans1=solve(n-x,x,y,z)+1;
    int ans2=solve(n-y,x,y,z)+1;
    int ans3=solve(n-z,x,y,z)+1;
    int ans=max(ans1,max(ans2,ans3));
    return ans;
}

int main()
{
    int n=7;
    int x=5;
    int y=2;
    int z=2;
    int ans=solve(n,x,y,z);
    if(ans<0)
    {
        ans=0;
    }
    cout<<"Answer is : "<<ans<<endl;
    return 0;
}