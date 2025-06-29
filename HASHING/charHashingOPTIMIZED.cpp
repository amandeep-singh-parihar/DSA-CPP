#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    int arr[n];
    map<int,int> mpp;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        mpp[arr[i]]++;
    }

    //map stores all the value in sorted order   
    /*how map stores the key value
    */ 

//    for(auto i:mpp)
//    {
//     cout<<i.first<<"->"<<i.second<<endl;
//    }

    int q;
    cin>>q;
    while(q--)
    {
        int number;
        cin>>number;
        cout<<mpp[number]<<" ";
    }

    return 0;
}