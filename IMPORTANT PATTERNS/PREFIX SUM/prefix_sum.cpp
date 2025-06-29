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

    // //method 1 without using any extra spaces
    // int arr[7]={6,3,-2,4,-1,0,-5};
    // for(int i=1;i<7;++i)
    // {
    //     arr[i]=arr[i]+arr[i-1];
    // }

    // for(int i=0;i<7;++i)
    // {
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    // return 0;

    //method 2 using extra spaces or usign extra array
    int arr[7]={6,3,-2,4,-1,0,-5};
    int prr[7];
    prr[0]=arr[0];
    for(int i=1;i<7;++i)
    {
        prr[i]=arr[i]+prr[i-1];
    }

    for(int i=0;i<7;++i)
    {
        cout<<prr[i]<<" ";
    }
    cout<<endl;
}
