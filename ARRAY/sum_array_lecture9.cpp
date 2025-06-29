//sum of the elements in an array 

#include<bits/stdc++.h>
using namespace std;
int sumarr(int arr[],int size)
{
    int sum=0;
    for(int i=0;i<size;i++)
    {
        sum=sum+arr[i];


    }
    return sum;
}
int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<"the sum of the elements in an array is : "<<sumarr(arr,n);


    return 0;

    
}