#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin>>s;
    //same logic with the capital chars there s[i]-'A'
    //and the cout<< hash[c-'A'];


    //precompute
    int hash[26]={0};
    for(int i=0;i<s.size();i++)
    {
        hash[s[i]-'a']++;
    }

    int q;
    cin>>q;
    while(q--)
    {
        char c;
        cin>>c;
        cout<<hash[c-'a']<<" ";
    }
    return 0;
}