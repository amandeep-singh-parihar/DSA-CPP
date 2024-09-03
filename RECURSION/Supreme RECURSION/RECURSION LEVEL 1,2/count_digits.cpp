#include<bits/stdc++.h>
using namespace std;

// static const bool __boost = []()
// {
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     return ios_base::sync_with_stdio(false);
// }();

int digit(int n)
{
    if(n==0) return 0;

    return 1+digit(n/10);
}

int main()
{
    int n;
    cout<<"enter the number : ";
    cin>>n;

    cout<<"number of digits for the given number "<<n<<" : ";
    cout<<digit(n);
    return 0;
}