#include<bits/stdc++.h>
using namespace std;

int cnt(int n)
{
    int c=0;
    vector<bool> isprime(n+1,true);
    isprime[0]=isprime[1]=false;
    for(int i=2;i<n;i++)
    {
        if(isprime[i])
        {
            c++;
            for(int j=2*i;j<=n;j+=i)
            {
                isprime[j]=false;
            }

        }
    }
    return c;
}

int main()
{
    int n;
    cin>>n;
    cout<<cnt(n);
    return 0;
}