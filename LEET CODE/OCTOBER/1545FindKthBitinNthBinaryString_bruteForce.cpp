// 1545. Find Kth Bit in Nth Binary String
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

string invert(string s)
{
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '1')
        {
            s[i] = '0';
        }
        else
        {
            s[i] = '1';
        }
    }
    return s;
}

string rev(string s)
{
    reverse(s.begin(), s.end());
    return s;
}

string sn(int n)
{
    if (n == 1)
    {
        return "0";
    }
    return sn(n - 1) + "1" + rev(invert(sn(n - 1)));
}

char findKthBit(int n, int k)
{
    // string s1="0";
    string s = sn(n);
    // cout << s << endl;
    return s[k - 1];
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << findKthBit(n, k);
    return 0;
}