// 796. Rotate String
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// TC O(1)
// SC O(1)
bool rotateString(string s, string goal)
{
    if (s.size() != goal.size())
        return false;
    s += s;
    if (s.find(goal) != string::npos)
        return true;
    return false;
}

// TC O(N)
// SC O(N)
bool _rotateString(string s, string goal)
{
    if (s.size() != goal.size())
        return false;
    for (int i = 0; i < s.size(); ++i)
    {
        rotate(s.begin(), s.begin() + 1, s.end());
        if (s == goal)
            return true;
    }
    return false;
}

int main()
{
    string s = "abcde", goal = "cdeab";
    cout << rotateString(s, goal);
    return 0;
}