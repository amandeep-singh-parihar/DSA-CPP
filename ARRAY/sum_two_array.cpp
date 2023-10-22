/*you   are given two numbers a and b in the form of two arrays a and b of lengths n and m respectively 
where each array element represents a digit you need to find the sum of these two numbers and return this 
sum in the form of an array*/

#include<bits/stdc++.h>
using namespace std;

vector<int> sum(vector<int >& arr,int m,vector<int >& brr,int n)
{
    int i=m-1,j=n-1;
    vector<int >ans;
    int carry=0;
    while(i>=0 && j>=0)
    {
        int sum=arr[i]+brr[j]+carry;
        carry=sum/10;
        sum=sum%10;
        ans.insert(ans.begin(),sum);
        i--,j--;
    }   

    while(i>=0)
    {
        int sum=arr[i]+carry;
        carry=sum/10;
        sum=sum%10;
        ans.insert(ans.begin(),sum);
        i--;
    }

    while(j>=0)
    {
        int sum=brr[j]+carry;
        carry=sum/10;
        sum=sum%10;
        ans.insert(ans.begin(),sum);
        j--;
    }
    while(carry!=0)
    {
        int sum=carry;
        carry=sum/10;
        sum=sum%10;
        ans.insert(ans.begin(),sum);
    }
    return ans;
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