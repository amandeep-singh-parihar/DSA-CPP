#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
int main()
{
    // string str="32";
    // int num=stoi(str);
    // cout<<num;
    // int ans=0;
    // while(num)
    // {
    //     int digit=num%10;
    //     ans=max(ans,digit*1);
    //     num=num/10;
    // }
    // cout<<endl;
    // cout<<ans;

    char maxi=max('0','1');
    int ans=maxi-'0';
    cout<<ans;

    return 0;

}