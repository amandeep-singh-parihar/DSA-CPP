/*you are given two numbers a and b in the form of two arrays a and b of lengths n and m respectively 
where each array element represents a digit you need to find the sum of these two numbers and return this 
sum in the form of an array*/

#include<bits/stdc++.h>
using namespace std;

vector<int> sum(vector<int >& a,int m,vector<int >& b,int n)
{
    int x=a[0],y=b[0];
    for(int i=1;i<m;i++)
    {
        x=x*10+a[i];
    }

    for(int j=1;j<n;j++)
    {
        y=y*10+b[j];
    }
    x=x+y;

    vector<int > v;
    while(x!=0)
    {
        int ans=x%10;
        v.insert(v.begin(),ans);
        x=x/10;
    }
    return v;

}
int print(vector<int >& arr)
{
    for(auto i:arr)
    {
        cout<<i<<" ";
    }
}

int main()
{
    vector<int> arr={1 ,2 ,3 ,4};
    vector<int > brr={6};

    vector<int> ans=sum(arr,arr.size(),brr,brr.size());
    print(ans);
    

    return 0; 
}