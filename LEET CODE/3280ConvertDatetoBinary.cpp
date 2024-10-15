#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

string calc(int num)
{
    string binary = "";
    while (num)
    {
        int digit = num & 1;
        binary += to_string(digit);
        num = num >> 1;
    }
    reverse(binary.begin(), binary.end());
    return binary;
}
string convertDateToBinary(string date)
{
    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int _date = stoi(date.substr(8, 2));
    return calc(year) + "-" + calc(month) + "-" + calc(_date);
}

int main()
{
    string date="2080-02-29";
    cout<<convertDateToBinary(date);
    return 0;
}