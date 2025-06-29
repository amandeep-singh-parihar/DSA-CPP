#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

//revision 2
int fact(int n)
{
    //base case
    if(n==1) return 1;

    return n*fact(n-1);
}

int main()
{
    int n;
    cout<<"enter the number : ";
    cin>>n;

    int ans=fact(n);
    cout<<ans;
    return 0;
}