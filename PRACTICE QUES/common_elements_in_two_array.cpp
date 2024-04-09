#include<bits/stdc++.h>
using namespace std;

void common(int arr1[],int arr2[],int size1,int size2)
{
    int i=0,j=0;
    while(i<size1 && j<size2)
    {
        if(arr1[i]<arr2[j])
        {
            i++;
        }else if(arr1[i]==arr2[j])
        {
            cout<<arr1[i]<<" ";
            i++,j++;
        }else{
            j++;
        }
    }
}

int main()
{
    int arr1[7]={2,2,2,2,10,100,4};
    int arr2[5]={1,2,2,10,11};
    common(arr1,arr2,7,5);
    return 0;
}