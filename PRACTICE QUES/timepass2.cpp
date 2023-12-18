#include<bits/stdc++.h>
using namespace std;

void swap(int arr[],int size)
{
    int s=0,e=size-1;
    while(s<=e)
    {
        swap(arr[s],arr[e]);
        s++,e--;
    }
}

int main()
{
    int size;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    swap(arr,size);
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}