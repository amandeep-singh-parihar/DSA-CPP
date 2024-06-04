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
    for(int i=1;i<4;++i)
    {
        for(int j=1;j<4-i;++j)
        {
            cout<<" ";
        }
        for(int j=1;j<=i;++j){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}