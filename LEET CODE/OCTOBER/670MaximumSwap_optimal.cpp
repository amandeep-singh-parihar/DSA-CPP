// 670. Maximum Swap
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
//revision needed
int maximumSwap(int num)
{
    string s = to_string(num);
    int n = s.length();

    vector<int> maxRight(10, -1);
    for (int i = 0; i < n; ++i)
    {
        int idx = s[i] - '0';
        maxRight[idx] = i;
    }

    for (int i = 0; i < n; ++i)
    {
        char currChar = s[i];
        int currDigit = currChar - '0';

        for (int digit = 9; digit > currDigit; digit--)
        {
            if (maxRight[digit] > i)
            {
                swap(s[i], s[maxRight[digit]]);
                return stoi(s);
            }
        }
    }
    return num;
}
int main()
{
    int num;
    cin >> num;
    cout << maximumSwap(num);
    return 0;
}