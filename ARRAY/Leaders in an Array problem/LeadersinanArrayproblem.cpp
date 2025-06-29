#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

vector<int> leaders(int a[], int n)
{
    vector<int>ans;
    for (int i = 0; i < n; ++i)
    {
        bool isL=true;
        for (int j = i + 1; j < n ; ++j)
        {
            if(a[i]<a[j])
            {
                isL=false;
                break;
            }
        }
        if(isL)
        {
            ans.push_back(a[i]);
        }
    }
    return ans;
}

int main()
{
    int a[5]={31,40,93,40,98};
    vector<int>ans=leaders(a,5);
    for(int i=0;i<ans.size();++i)
    {
        cout<<ans[i]<<" ";
    }

    return 0;
}