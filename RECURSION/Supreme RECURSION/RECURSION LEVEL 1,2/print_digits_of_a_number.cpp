// print digits of a number
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
// revision 2
void PrintNUMs(int n, vector<int> &ans)
{
    // base case
    if (n == 0)
    {
        return;
    }

    // 1case solve
    int rem = n % 10;
    ans.push_back(rem);
    n /= 10; // ans will be in reverse order as we are processing first and recursive call second

    // rs call
    PrintNUMs(n, ans);
}

void PrintNum(int n)
{
    if (n == 0)
        return;

    // recursion
    //  int newValueN=n/10;
    PrintNum(n / 10);
    // print in correct order as we are recursive call fisrt and processing second

    // 1case solve
    int rem = n % 10;
    cout << rem << " ";
}

int main()
{
    int n;
    cin >> n;
    vector<int> ans;
    PrintNUMs(n, ans);

    // for reversing the verctor
    reverse(ans.begin(), ans.end());
    for (auto z : ans)
    {
        cout << z << " ";
    }
    cout << endl;
    return 0;
}