#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

void solve(vector<string> &res, int n, int open, int close, string output)
{
    if (open == 0 && close == 0)
    {
        res.push_back(output);
        return;
    }

    // incluse open
    if (open > 0)
    {
        output.push_back('(');
        solve(res, n, open - 1, close, output);
        // backtrack
        output.pop_back();
    }

    //as the recusion call goes on the open become zero at a time and now the closing bracket must be greter than opening
    if (close > open)
    {
        output.push_back(')');
        solve(res, n, open, close - 1, output);
        // backtrack
        output.pop_back();
    }
}

vector<string> generate(int n)
{
    vector<string> res;
    int open = n;
    int close = n;
    string output = "";
    solve(res, n, open, close, output);
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<string> ans = generate(n);
    cout<<"[";
    for (int i=0;i<ans.size();++i)
    {
        cout << ans[i] << "";
        if(i<ans.size()-1)
        {
            cout<<",";
        }
    }
    cout<<"]";
    cout << endl;
    return 0;
}