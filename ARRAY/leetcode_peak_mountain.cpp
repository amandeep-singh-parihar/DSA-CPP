//***********************************************FIND PEAK ELEMENT IN MOUNTAIN ARRAY*****************************************

#include<bits/stdc++.h>
using namespace std;

int peak(int arr[],int n)
{
    int start=0,end=n-1;
    int mid=start+(end-start)/2;
    while(start<end)
    {
        if(arr[mid]<arr[mid+1])
        {
            start=mid+1;
        }else{
            end=mid;
        }
        mid=start+(end-start)/2;

    }
    return end;
}

int main()
{
    int arr[5]={0,1,3,1,-1};  //returns the index of '3' which is 2
    cout<<peak(arr,5);
    return 0;
}