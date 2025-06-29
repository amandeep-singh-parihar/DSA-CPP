//swapping alternate elements of an array by CODE HELP

#include<bits/stdc++.h>
using namespace std;


int printarr(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}



void swapAlternate(int arr[],int size)
{
    for(int i=0;i<size;i+=2)
    {
        if(i+1<size)
        {
            swap(arr[i],arr[i+1]);
        }
    }
}
int main()
{
    int num[5]={1,2,4,325,5};
    swapAlternate(num,5);

    printarr(num,5);
    return 0;

}