#include<bits/stdc++.h>
using namespace std;
int merge(int arr1[],int n,int arr2[],int m)
{
    int i=n-1,j=0;
    while(i>=0 && j<m)
    {
        if(arr1[i]>arr2[j])
        {
            swap(arr1[i],arr2[j]);
            i--,j++;
        }
        else{
            break;
        }
    }
    
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);

}

void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{

    int arr1[5]={1,3,5,7,8};
    int arr2[3]={2,4,6};
    
    //int arr3[8]={0};

    merge(arr1,5,arr2,3);

    print(arr1,5);
    //cout<<endl;
    print(arr2,3);

    return 0;
}