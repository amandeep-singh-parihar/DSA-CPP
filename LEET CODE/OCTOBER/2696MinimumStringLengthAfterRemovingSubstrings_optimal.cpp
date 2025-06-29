//2696. Minimum String Length After Removing Substrings
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

int minLength(string s)
{
    int n = s.size();
    int i = 0; // read
    int j = 1; // write
    while (j < n)
    {
        if (i < 0)
        {
            ++i;
            s[i] = s[j];
        }
        else if ((s[i] == 'A' && s[j] == 'B') || (s[i] == 'C' && s[j] == 'D'))
        {
            --i;
        }
        else
        {
            ++i;
            s[i] = s[j];
        }
        ++j;
    }
    return i + 1;
}

int main()
{
    string s;
    cin >> s;
    cout << minLength(s);
    return 0;
}