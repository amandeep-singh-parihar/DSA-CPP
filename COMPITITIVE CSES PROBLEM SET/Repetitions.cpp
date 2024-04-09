#include <bits/stdc++.h>
using namespace std;

int Repetitions(string s)
{
    int ans = 1, count = 1;
    for (int i = 1; i < s.length(); ++i)
    {
        if (s[i] == s[i - 1])
        {
            count++;
        }
        else
        {
            count = 1;
        }
        ans = max(ans, count);
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout << Repetitions(s);
    return 0;
}