// 796. Rotate String
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

bool rotateString(string s, string goal)
{
    if (s.size() != goal.size())
    {
        return false;
    }
    string d = s + s;
    return d.find(goal) != string::npos;
}

int main()
{
    string s, goal;
    cin >> s >> goal;
    cout << rotateString(s, goal) << endl;
    return 0;
}