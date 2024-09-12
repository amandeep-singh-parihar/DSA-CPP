#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

void decTobin(int n)
{
    int bin[32];

    int i=0;
    while(n)
    {
        bin[i]=n%2;
        n/=2;
        ++i;
    }
    for(int j=i-1;j>=0;--j)
    {
        cout<<bin[j];
    }
}

int main()
{
    int n;
    cin>>n;
    decTobin(n);
    return 0;
}