#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
//revision 2
string add(string num1, string num2)
{
    string ans;
    int i = num1.size() - 1, j = num2.size() - 1;
    int sum, carry = 0;
    // as num2 is smaller it exhauste first
    while (j >= 0)
    {
        sum = (num1[i] - '0') + (num2[j] - '0') + carry;
        carry = sum / 10;
        char c = '0' + sum % 10;
        ans += c;
        i--, j--;
    }
    // the rest num1 which is left
    while (i >= 0)
    {
        sum = num1[i] - '0' + carry;
        carry = sum / 10;
        char c = '0' + sum % 10;
        ans += c;
        i--;
    }
    if (carry)
        ans += '1';
    reverse(ans.begin(), ans.end());
    return ans;
}

string addStrings(string num1, string num2)
{
    if (num1.size() > num2.size())
        return add(num1, num2);
    else
        return add(num2, num1);
}

int main()
{
    string num1 = "11";
    string num2 = "123";
    cout << addStrings(num1, num2);
    return 0;
}