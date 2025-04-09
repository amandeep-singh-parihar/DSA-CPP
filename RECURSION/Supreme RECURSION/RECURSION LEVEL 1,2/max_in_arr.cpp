#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

//revision 2

// int maxi(int arr[],int n)
// {
//     //bc
//     if(n==1) return arr[0];

//     int maxInRest=maxi(arr,n-1);

//     return max(arr[n-1],maxInRest);
// }

void findMax(int arr[],int n,int i,int& maxi)
{
    if(i>n-1)
    {
        return;
    }

    //1 case solve
    if(arr[i]>maxi)
    {
        maxi=arr[i];
    }

    //recursion
    findMax(arr,n,i+1,maxi);
}

int maxi(int arr[],int n,int i,int _maxi){
    if(i>=n) return _maxi;

    if(arr[i]>=_maxi) _maxi=max(_maxi,arr[i]);

    return maxi(arr,n,i+1,_maxi);
}

int main(){
    int arr[5]={1,2,30,-1,10};
    cout<<maxi(arr,5,0,INT_MIN);
}

// int main()
// {
//     int n;
//     cin>>n;

//     int arr[n];
//     for(int i=0;i<n;++i)
//     {
//         cin>>arr[i];
//     }
//     // cout<<maxi(arr,n);
//     int i=0;
//     int maxi=INT_MIN;
//     findMax(arr,n,i,maxi);
//     cout<<maxi;

//     return 0;
// }