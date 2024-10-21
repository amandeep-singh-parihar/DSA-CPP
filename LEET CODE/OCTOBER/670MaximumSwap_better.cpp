// 670. Maximum Swap
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
//revision 1
int maximumSwap(int num)
{
    string s = to_string(num);
    int n = s.length();
    vector<int> maxRight(n);

    maxRight[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; --i)
    {
        int rightMaxIdx = maxRight[i + 1];
        int rightMaxElem = s[rightMaxIdx];

        maxRight[i] = (s[i] > rightMaxElem) ? i : rightMaxIdx;
    }

    for (int i = 0; i < n; ++i)
    {
        int maxRightIdx = maxRight[i];
        int maxRightElem = s[maxRightIdx];
        if (s[i] < maxRightElem)
        {
            swap(s[i], s[maxRightIdx]);
            return stoi(s);
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