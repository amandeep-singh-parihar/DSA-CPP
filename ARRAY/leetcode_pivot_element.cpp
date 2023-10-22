//*****************************************RETURN THE PIVOT ELEMENT IN A ROTATED ARRAY**************************************************


#include<bits/stdc++.h>
using namespace std;

int pivot(int arr[],int n)
{
    int s=0,e=n-1;
    int mid=s+(e-s)/2;
    while(s<e)
    {
        if(arr[mid]>=arr[0])
        {
            s=mid+1;
        }else{
            e=mid;
        }
        mid=s+(e-s)/2;

    }
    return e;
}


int main()
{
    int arr[7]={6,7,1,2,3,4,5}; //here the pivot element '1' so the index is 2
    cout<<pivot(arr,7);
    return 0;
}