//you are given an array "arr" of "N" containing each number between 1 to N-1 atleast once .there is a single integer value 
//that is present in the array twice . your task is to find the duplicate integer in the array.
//the numbers must be between 0 to size-1

#include<bits/stdc++.h>
using namespace std;

int duplicate(int arr[],int n)
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans=ans^arr[i];
    }

    for(int i=1;i<n;i++)
    {
        ans=ans^i;
    }

    return ans;
}

int main()
{
    int arr[9]={1,2,3,4,5,6,7,8,8};
    cout<<duplicate(arr,9);
    return 0;
}