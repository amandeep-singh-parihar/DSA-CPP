//567. Permutation in String
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
// sliding window

bool checkInclusion(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    if (n > m)
    {
        return false;
    }

    vector<int> s1_ferq(26, 0);
    vector<int> s2_ferq(26, 0);
    for (auto it : s1)
    {
        s1_ferq[it - 'a']++;
    }

    int i = 0;
    int j = 0;
    while (j < m)
    {
        s2_ferq[s2[j] - 'a']++;
        if (j - i + 1 > n)
        {
            s2_ferq[s2[i] - 'a']--;
            ++i;
        }
        if (s1_ferq == s2_ferq)
        {
            return true;
        }
        ++j;
    }
    return false;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << checkInclusion(s1, s2);
    cout << endl;
    return 0;
}
//T.C : O(m+n)
//S.C : O(26)
