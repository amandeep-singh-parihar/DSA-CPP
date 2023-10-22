//swaping alternate elements in an array by amandeep singh parihar

#include<bits/stdc++.h>
using namespace std;
int alternaterev(int arr[],int size)
{
    int start=0;
    int second_start=1;
    while(start<=size && second_start<=size-1)
    {
        swap(arr[start],arr[second_start]);
        start=start+2;
        second_start=second_start+2;
    }
}
int printarr(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{

    int arr[6]={1,2,3,4,5,6};

    alternaterev(arr,6);

    printarr(arr,6);
}