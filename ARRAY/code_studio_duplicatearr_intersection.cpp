//*******************************************INTERSECTION OF ARRAY********************************************************

//you are given two array of size N and M. both are in sorted order of non- decreasing .
// you hava to find the duplicate elements in the array
/*

sample input

2
6 4
1 2 2 2 3 4  //
2 2 3 3      //
3 2
1 2 3
3 4  


output

2 2 3
3 

*/

//intersection of two arrays by CODE HELP ------------------>*********OPTIMIZED*********

#include<bits/stdc++.h>
using namespace std;
void intersection(int arr[],int brr[],int n,int m)
{
    int i=0;
    int j=0;
    while(i<n && j<m)
    {
        if(arr[i]<brr[j])
        {
            i++;
        }else if(arr[i]==brr[j])
        {
            cout<<arr[i]<<" ";
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
}
int main()
{
    int arr[6]={1,2,2,2,3,4};
    int brr[4]={2,2,3,3};


    intersection(arr,brr,5,8);


    return 0;
}