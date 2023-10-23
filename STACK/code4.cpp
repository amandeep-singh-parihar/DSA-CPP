#include<bits/stdc++.h>
using namespace std;

vector<int> NSE_left(vector<int>& arr,int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i=0;i<n;++i)
    {
        int current=arr[i];
        //+a-
        while(!s.empty() && current<=arr[s.top()] && s.top()!=-1)
        {
            s.pop();
        }
        if(s.empty())
        {
            ans[i]=-1;
        }else{
            ans[i]=s.top();
        }
        s.push(i);
    }
    return ans;
}

vector<int> NSE_right(vector<int>& arr,int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i=n-1;i>=0;--i)
    {
        int current=arr[i];
        //+a-
        while(!s.empty() && current<=arr[s.top()] && s.top()!=-1)
        {
            s.pop();
        }
        if(s.empty())
        {
            ans[i]=-1;
        }else{
            ans[i]=s.top();
        }
        s.push(i);
    }
    return ans;
}

int MAH(vector<int>& arr,int n)
{
    vector<int> rb;
    rb=NSE_right(arr,n);

    vector<int> lb;
    lb=NSE_left(arr,n);

    int maxarea=0;
    for(int i=0;i<n;i++)
    {
        if(rb[i]==-1)
        {
            rb[i]=n;
        }
        int width=rb[i]-lb[i]-1;
        int area=arr[i]*width;
        maxarea=max(area,maxarea);
    }
    return maxarea;

}

int main()
{
    // Example usage:
    vector<int> arr = {2,1,5,6,2,3};
    int n = arr.size();
    int maxArea = MAH(arr, n);
    cout << "Maximum Area in a Histogram: " << maxArea << endl;
    return 0;
}