#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

long merge(vector<int>&arr,vector<int>&temp,int start,int end,int mid)
{
    int c=0;
    int i=start,j=mid+1,k=start;
    while(i<=mid && j<=end)
    {
        if(arr[i]>arr[j])
        {
            temp[k++]=arr[j++];
            c+=mid-i+1;
        }else{
            temp[k++]=arr[i++];
        }
    }

    while(i<=mid)
    {
        temp[k++]=arr[i++];
    }

    while(j<=end)
    {
        temp[k++]=arr[j++];
    }

    while(start<=end)
    {
        arr[start]=temp[start];
        start++;
    }
    return c;
}

long mergeSort(vector<int>&arr,vector<int>&temp,int start,int end)
{
    long count=0;
    if(start>=end)
    {
        return 0;
    }

    int mid=start+(end-start)/2;

    count+=mergeSort(arr,temp,start,mid);
    count+=mergeSort(arr,temp,mid+1,end);
    count+=merge(arr,temp,start,end,mid);
    return count;
}

long countInversions(vector<int>&arr)
{
    long count=0;
    vector<int>temp(arr.size(),0);
    count=mergeSort(arr,temp,0,arr.size()-1);
    return count;
}

int main()
{
    vector<int> arr = {2, 1, 3, 1, 2};
    int n = arr.size();
    cout << countInversions(arr);
    return 0;
}