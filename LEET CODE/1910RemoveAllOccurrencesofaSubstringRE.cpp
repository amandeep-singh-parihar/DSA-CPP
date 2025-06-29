#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
//revision 1
void rR(string &s, string &part)
{
    if (s.find(part) != string::npos)
    {
        string left = s.substr(0, s.find(part));
        string right = s.substr(s.find(part) + part.size(), s.size());
        s = left + right;
        rR(s, part);
    }
    else
    {
        return;
    }
}

string removeOccurrences(string &s, string &part)
{
    rR(s, part);
    return s;
}

int main()
{
    string s = "daabcbaabcbc";
    string part = "abc";
    cout << removeOccurrences(s, part) << endl;
    return 0;
}