#include<bits/stdc++.h>
using namespace std;

vector<int> NGE(vector<int>& arr,int size)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(size);
    for(int i=size-1;i>=0;--i)
    {
        int current=arr[i];
        while(!s.empty() && current>=s.top())
        {
            s.pop();
        }

        if(s.empty())
        {
            ans[i]=-1;
        }else{
            ans[i]=s.top();
        }
        s.push(current);
    }
}

int main()
{
    int n;
    cout<<"enter the number of elements : ";
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
    }

    vector<int> nge=NGE(arr,n);
    for(int i=0;i<n;++i)
    {
        cout<<nge[i]<<" ";
    }
    cout<<endl;
    return 0;
}