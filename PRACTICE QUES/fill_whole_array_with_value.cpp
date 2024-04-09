#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[10];
    //arr+9 it means filling the whole array with till 9 with value 2 
    fill(arr,arr+9,2);

    for(int i=0;i<9;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}