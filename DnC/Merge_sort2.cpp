#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

void merge(vector<int>&arr,vector<int>&temp,int start,int end,int mid)
{
    int i=start,j=mid+1,k=start;
    while(i<=mid && j<=end)
    {
        if(arr[i]<=arr[j])
        {
            temp[k++]=arr[i++];
        }else{
            temp[k++]=arr[j++];
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

    //put all in the array now
    while(start<=end)
    {
        arr[start]=temp[start];
        ++start;
    }

}

void mergeSORT(vector<int>&arr,vector<int>&temp,int start,int end)
{
    if(start>=end) return;

    int mid=start+(end-start)/2;

    mergeSORT(arr,temp,start,mid);
    mergeSORT(arr,temp,mid+1,end);

    merge(arr,temp,start,end,mid);
}

int main()
{
    vector<int>arr = {4, 3, 2, 1, 0, 12, -2, 12, 0, -1, -1};
    int n = arr.size();

    vector<int>temp(arr.size(),0);

    cout << endl;
    mergeSORT(arr,temp, 0, n - 1);
    cout << endl;
    cout << "[";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
        if (i < n - 1)
            cout << ",";
    }
    cout << "]";
    cout << endl;
    return 0;
}