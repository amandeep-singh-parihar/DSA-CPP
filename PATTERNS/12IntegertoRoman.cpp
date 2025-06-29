#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

string intToRoman(int num)
{
    int n[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string s[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int i = 0;
    string str = "";
    while (num > 0)
    {
        if (num >= n[i])
        {
            str += s[i];
            num -= n[i];
        }
        else
        {
            i++;
        }
    }
    return str;
}

int main()
{
    int num;
    cin>>num;
    cout<<intToRoman(num)<<endl;
    return 0;
}