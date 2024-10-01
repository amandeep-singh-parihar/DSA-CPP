#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
//revision 1
int nStairs(int n)
{
    if(n<0) return 0;
    if(n==0 || n==1) return 1;

    return nStairs(n-1)+nStairs(n-2);


}

int main()
{
    int n;
    cin>>n;
    cout<<nStairs(n);
    return 0;
}