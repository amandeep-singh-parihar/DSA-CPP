//simple using count
#include<bits/stdc++.h>
using namespace std;

int totalOCC(int arr[],int key,int size)
{
    int count=0;
    for(int i=0;i<size;i++)
    {
        if(arr[i]==key)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int arr[5]={1,2,2,3,3};
    int key;
    cin>>key;
    cout<<totalOCC(arr,key,5);
    return 0;
}