#include <bits/stdc++.h>
using namespace std;

int solve(int n,int arr[],string v)
{
    int mini=INT_MAX;
    for(int i=0;i<n;++i)
    {
        //fail test case
        if(arr[i]+(v[i]-'0')==arr[i])
        {
            mini=min(mini,arr[i]);
        }
    }
    return mini;
    
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int s[n];
        for(int i=0;i<n;i++){
            cin>>s[i];
        }
        string v;
        cin>>v;
        cout<<solve(n,s,v)<<endl;
    }

}
