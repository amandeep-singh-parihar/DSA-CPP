// previous smaller element
#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// revision 1

vector<int> previousSmallerElement(vector<int> &arr, int n)
{
    stack<int>s;
    s.push(-1);
    vector<int>ans(n);
    // for(int i=0;i<arr.size();++i)
    // {
    //     while(arr[i]<=s.top())
    //     {
    //         s.pop();
    //     }
    //     ans[i]=s.top();
    //     s.push(arr[i]);
    // }
    //below one is easy to remember
    for(int i=0;i<arr.size();++i)
    {
        while(s.top()!=-1 && arr[i]<=s.top())
        {
            s.pop();
        }
        if(s.top()==-1)
        {
            ans[i]=-1;
        }else{
            ans[i]=s.top();
        }
        s.push(arr[i]);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> result = previousSmallerElement(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}