#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

//revision 1
int two(int n)
{
    if(n==0) return 1;
    if(n==1) return 2;

    return 2*two(n-1);
}

int main()
{
    int n;
    cout<<"enter the power of 2 : ";
    cin>>n;

    cout<<"2^"<<n<<" = "<<two(n);

    return 0;
}