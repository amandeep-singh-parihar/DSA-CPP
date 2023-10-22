//you are given an array "arr" of "N" containing each number between 1 to N-1 atleast once .there is a single integer value 
//that is present in the array twice . your task is to find the duplicate integer in the array.


#include<iostream>
using namespace std;
int duplicate(int arr[],int size)
{
    int ans=0;
    for(int i=0;i<size;i++)
    {
        ans=ans^arr[i];
    }

    for(int i=1;i<size;i++)
    {
        ans=ans^i;
    }
    return ans;
}


int main()
{
    int arr[7]={1,6,4,2,3,5,4}; // output ---> 4

    cout<<duplicate(arr,7);
    

    return 0;
    

}