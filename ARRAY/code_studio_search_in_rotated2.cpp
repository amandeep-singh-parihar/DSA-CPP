//***************************************SEARCHING AN ELEMENT IN A SORTED ROTATED ARRAY****************************************
// 2 way
#include<bits/stdc++.h>
using namespace std;

int search(int arr[],int size,int key)
{
    int s=0,e=size-1;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(arr[mid]==key) return mid;

        if(arr[s]<=arr[mid])//going into the right sorted part
        {
            if(arr[s]<=key && key<arr[mid])
            {
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        else{//going into the left sortd part
            if(arr[mid]<key && key<=arr[e])
            {
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
    }
    return -1;
}

int main()
{
    int arr[7]={4,5,6,7,0,1,2};
    int key;
    cout<<"Enter the element you want to search # ";
    cin>>key;
    cout<<"Index of the "<<key<<" is "<<search(arr,7,key);
    return 0;
}