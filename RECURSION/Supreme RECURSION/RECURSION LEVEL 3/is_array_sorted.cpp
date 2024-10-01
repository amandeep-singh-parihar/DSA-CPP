#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

bool is_sorted(int arr[],int& n,int i)
{
    //base case
    if(i>=n-1) return true;

    //if this condition occur then must not be sorted
    if(arr[i]>arr[i+1]) return false;

    //recursion
    return is_sorted(arr,n,i+1);

}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    int i=0;
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
    }
    cout<<(is_sorted(arr,n,i)?"Sorted":"Not sorted");
    return 0;
}