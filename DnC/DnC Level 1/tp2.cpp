#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

int partition(int arr[],int s,int e)
{
    int pivotIndex=s;
    int pivotElement=arr[s];
    int count=0;
    for(int i=s+1;i<=e;++i)
    {
        if(arr[i]<=pivotElement)
        {
            count++;
        }
    }

    int rightIndex=s+count;
    swap(arr[pivotIndex],arr[rightIndex]);
    pivotIndex=rightIndex;


    int i=s;
    int j=e;
    while(i<pivotIndex && j>pivotIndex)
    {
        while(arr[i]<=pivotElement)
        {
            ++i;
        }
        while(arr[j]>pivotElement)
        {
            --j;
        }
        if(i<pivotIndex && j>pivotIndex)
        {
            swap(arr[i],arr[j]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[],int s,int e)
{
    if(s>=e) return;

    int p = partition(arr,s,e);

    //left call
    quickSort(arr,s,p-1);

    //right call
    quickSort(arr,p+1,e);
}

int main()
{
    int arr[] = {8, 1, 3, 4, 20, 50, 30, 1, 1, 1, 3, 4, 5, 5, 5, 5, 5, 6, 7, 8, 9, 9, 9};
    int n = 23;

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
    return 0;
}