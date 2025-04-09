// binary search using recursion
#include<bits/stdc++.h>
using namespace std;
// static const bool __boost = []()
// {
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     return ios_base::sync_with_stdio(false);
// }();
//revision 1
int bin_srch(vector<int>& arr,int s,int e,int& key)
{
    //base case 1
    if(s>e) return -1;

    int mid=s+(e-s)/2;

    //base case 2
    if(arr[mid]==key) return mid;

    if(arr[mid]<key)
    {
        return bin_srch(arr,mid+1,e,key);
    }else{
        return bin_srch(arr,s,mid-1,key);
    }

    //we can also use ternary operator on this
    // return (arr[mid]<key) ?  bin_srch(arr,mid+1,e,key) :  bin_srch(arr,s,mid-1,key);
}


int main()
{
    vector<int>v;
    int n;
    cout<<"enter the size of the array : ";
    cin>>n;
    int element;
    cout<<"enter all the elements : ";
    for(int i=0;i<n;++i)
    {
        cin>>element;
        v.push_back(element);
    }
    int s=0;
    int e=n-1;
    int key;
    cout<<"enter the key to search : ";
    cin>>key;
    cout<<"The key is at the index : "<<bin_srch(v,s,e,key);
    return 0;
}