#include<bits/stdc++.h>
using namespace std;

void printPrime(int n)
{
    vector<bool> prime(n+1,true);

    for(int i=2;i<n;i++)
    {
        if(prime[i])
        {
            for(int j=2*i;j<=n;j=j+i)
            {
                prime[j]=false;
            }
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(prime[i])
        {
            cout<<i<<" ";
        }
    }
}

int main()
{
    int n;
    cin>>n;
    printPrime(n);
    return 0;
}