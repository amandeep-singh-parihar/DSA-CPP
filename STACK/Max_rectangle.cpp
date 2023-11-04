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
        //-a+
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

int maxArea(vector<vector<int>>& mat,int n,int m)
{
    int maxarea=0;
    vector<int> height(m,0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;++j)
        {
            if(mat[i][j]==1) height[j]++;
            else height[j]=0; 
        }
        maxarea=max(MAH(height,m),maxarea);
    }
    return maxarea;
}

int main() {
    int n, m;
    cout << "Enter the number of rows: ";
    cin >> n;
    cout << "Enter the number of columns: ";
    cin >> m;
    
    vector<vector<int>> mat(n, vector<int>(m));

    cout << "Enter the binary matrix elements (0 or 1):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; ++j) {
            cin >> mat[i][j];
        }
    }

    int mx = maxArea(mat, n, m);

    cout << "The maximum area of a rectangle in the binary matrix is: " << mx << endl;

    return 0;
}