// 8. String to Integer (atoi)
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// without recursion
// TC O(N)
// SC O(1)
int myAtoi(string s)
{
    // remove all the leading spaces
    int i = 0;
    while (i < s.size() && isspace(s[i]))
    {
        ++i;
    }
    s = s.substr(i); // no leading spaces

    long long ans = 0;
    bool neg = false;
    for (int i = 0; i < s.size(); ++i)
    {
        // check for the - and + sign
        if (i == 0)
        {
            if (s[i] == '-')
            {
                neg = true;
                continue;
            }
            else if (s[i] == '+')
            {
                neg = false;
                continue;
            }
        }

        // now check for the numbers only
        if (s[i] >= '0' && s[i] <= '9')
        {
            int digit = s[i] - '0';
            ans = ans * 10 + digit;

            // check for the neg and positive and underflow and overflow
            if (neg)
            {
                long long _ans = -ans;
                if (_ans < INT_MIN)
                {
                    return INT_MIN;
                }
            }
            else
            {
                if (ans > INT_MAX)
                {
                    return INT_MAX;
                }
            }
        }
        else
        {
            break;
        }
    }
    if (neg)
    {
        ans = -ans;
    }
    return (int)ans;
}

// with recursion
int _myAtoi(string s){
    
}
int main()
{
    string str = "21474836460";
    cout<<myAtoi(str);
    return 0;
}