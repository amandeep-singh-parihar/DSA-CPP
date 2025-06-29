// 1903. Largest Odd Number in String
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// TC O(N)
// SC O(1)
string largestOddNumber(string num)
{
    int n = num.size();
    string ans = "";
    if ((num[n - 1] - '0') % 2)
    {
        return num;
    };
    int i = n - 1;
    while (i >= 0)
    {
        if ((num[i] - '0') % 2 == 0)
        {
            --i;
        }
        else
        {
            break;
        }
    }
    ans += num.substr(0, i + 1);
    return ans;
}

int main()
{
    string num = "4206522";
    cout<<largestOddNumber(num);
    return 0;
}