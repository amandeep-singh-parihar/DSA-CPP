// 678. Valid Parenthesis String
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// BRUTE
// TC O(3^N)
// SC O(N)
// bool solve(string s, int index, int cnt)
// {
//     if (cnt < 0)
//         return false;
//     if (index == s.size())
//         return cnt == 0;

//     if (s[index] == '(')
//     {
//         return solve(s, index + 1, cnt + 1);
//     }
//     else if (s[index] == ')')
//     {
//         return solve(s, index + 1, cnt - 1);
//     }
//     else if (s[index] == '*')
//     {
//         return solve(s, index + 1, cnt + 1) ||
//                solve(s, index + 1, cnt - 1) || solve(s, index + 1, cnt);
//     }
//     return false;
// }
// bool checkValidString(string s)
// {
//     return solve(s, 0, 0);
// }

// OPTIMAL
// TC O(N)
// SC O(1)
bool checkValidString(string s)
{
    int min = 0, max = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '(')
        {
            ++min, ++max;
        }
        else if (s[i] == ')')
        {
            --min, --max;
        }
        else
        {
            --min, ++max;
        }
        if (min < 0)
            min = 0;
        if (max < 0)
            return false;
    }
    return min == 0;
}

int main()
{
    string str;
    cin >> str;
    cout << checkValidString(str);
    return 0;
}