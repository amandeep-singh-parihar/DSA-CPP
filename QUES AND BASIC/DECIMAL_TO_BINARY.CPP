#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
//gives the ans in string format
int main()
{
    int n;
    cin>>n;
    string binary="";
    if(n==0)
    {
        binary="0";
    }else{
        while(n)
        {
            int digit=n&1;
            binary+=to_string(digit);
            n=n>>1;
        }
        reverse(binary.begin(),binary.end());
    }
    cout<<binary;

    return 0;
}