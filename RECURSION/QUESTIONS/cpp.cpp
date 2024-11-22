#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();


void merge(int arr[],int low,int high)
{
    int mid=low+(high-low)/2;
    int size1=mid-low+1,size2=high-mid;
    int arr1[size1];
    int arr2[size2];

    int k=low;
    for(int i=0;i<size1;++i)
    {
        arr1[i]=arr[k++];
    }
    k=mid+1;
    for(int i=0;i<size2;++i)
    {
        arr2[i]=arr[k++];
    }
    int i=0,j=0;
    k=low;
    while(i<size1 && j<size2)
    {
        if(arr1[i]<arr2[j])
        {
            arr[k++]=arr1[i++];
        }else{
            arr[k++]=arr2[j++];
        }
    }
    while(i<size1)
    {
        arr[k++]=arr1[i++];
    }

    while(j<size2)
    {
        arr[k++]=arr2[j++];
    }

}

void mergeSORT(int arr[],int low,int high)
{
    if(low==high) return ;
    int mid=low+(high-low)/2;
    mergeSORT(arr,0,mid);
    mergeSORT(arr,mid+1,high);
    merge(arr,low,high);
}

int main()
{
    int arr[]={4,3,2,1,0,12,-2,12,0,-1,-1};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<endl;
    mergeSORT(arr,0,n-1);
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}