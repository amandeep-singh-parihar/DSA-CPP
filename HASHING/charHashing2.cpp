#include<bits/stdc++.h>
using namespace std;
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    string s;
    cin>>s;


    //precompute
    int hash[256]={0};
    for(int i=0;i<s.size();i++)
    {
        //here s[i] auto coverts it into int
        hash[s[i]]++;
    }

    int q;
    cin>>q;
    while(q--)
    {
        char c;
        cin>>c;
        cout<<hash[c]<<" ";
    }
    return 0;
}