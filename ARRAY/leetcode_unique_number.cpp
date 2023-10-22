//you have been given an array of size N. where N is equal to [2M+1].Now in the given array 'M' numbers are present twice
//and one number present only once. find and return that one number.

#include<bits/stdc++.h>
using namespace std;
int findUniques(int *arr,int size)
{
    int ans=0;
    for(int i=0;i<size;i++)
    {
        ans=ans^arr[i];
    }
    return ans;
}


int main()
{
    int arr[11]={1,2,3,1,2,3,5,5,6,8,8};
    cout<<findUniques(arr,11);


}