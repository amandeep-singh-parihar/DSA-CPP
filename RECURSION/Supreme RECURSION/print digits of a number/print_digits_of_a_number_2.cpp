#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

void PrintNum(int n)
{
    if(n==0) return;

    //recursion 
    // int newValueN=n/10;
    PrintNum(n/10);


    //1case solve
    int rem=n%10;
    cout<<rem<<" ";
}

int main()
{
    int n;
    cin>>n;
    if(n==0) cout<<"0";
    PrintNum(n);


    return 0;
}