#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

void print(int arr[],int n,int s,int e)
{
    cout<<"{ ";
    for(int i=s;i<=e;++i)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"}"<<endl;
}

void printSubarray(int arr[],int n)
{
    for(int s=0;s<n;++s)
    {
        for(int e=s;e<n;++e)
        {
            print(arr,n,s,e);
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
    }
    printSubarray(arr,n);
    return 0;
}