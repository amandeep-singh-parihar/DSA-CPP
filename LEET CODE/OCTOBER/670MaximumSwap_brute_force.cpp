// 670. Maximum Swap
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

int maximumSwap(int num)
{
    vector<int> res;
    vector<int> temp;
    while (num)
    {
        int digit = num % 10;
        res.push_back(digit);
        num = num / 10;
    }
    reverse(res.begin(), res.end());
    temp = res;
    for (int i = 0; i < res.size(); ++i)
    {
        for (int j = i + 1; j < res.size(); ++j)
        {
            if (res[i] < res[j])
            {
                swap(res[i], res[j]);

                int resNum = 0, tempNum = 0;
                for (int d : res)
                {
                    resNum = resNum * 10 + d;
                }
                for (int d : temp)
                {
                    tempNum = tempNum * 10 + d;
                }
                if (tempNum < resNum)
                {
                    temp = res;
                }
                swap(res[i], res[j]);
            }
        }
    }
    int number = 0;
    for (int digit : temp)
    {
        number = number * 10 + digit;
    }
    return number;
}

int main()
{
    int num;
    cin >> num;
    cout << maximumSwap(num) << endl;
    return 0;
}