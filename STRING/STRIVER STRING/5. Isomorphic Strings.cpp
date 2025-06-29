// 205. Isomorphic Strings
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// TC O(N)
// SC O(N+N)
bool isIsomorphic(string s, string t)
{
    int n = s.size();
    map<char, char> sMap, tMap;

    for (int i = 0; i < n; ++i)
    {
        if (sMap.count(s[i]) && sMap[s[i]] != t[i])
            return false;

        if (tMap.count(t[i]) && tMap[t[i]] != s[i])
            return false;

        sMap[s[i]] = t[i];
        tMap[t[i]] = s[i];
    }
    return true;
}

int main()
{
    // string s = "egg", t = "add";
    string s = "foo", t = "bar";

    cout << isIsomorphic(s, t);
    return 0;
}