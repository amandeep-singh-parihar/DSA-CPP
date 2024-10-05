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
    int n;
    cin>>n;
    int* arr=new int[n];
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
    }

    for(int i=0;i<n;++i)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    delete []arr;
    return 0;
}