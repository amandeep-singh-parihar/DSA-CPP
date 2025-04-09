// INCLUDE EXCLUDE PATTERN
// INCLUDE EXCLUDE PATTERN
// INCLUDE EXCLUDE PATTERN
// INCLUDE EXCLUDE PATTERN
// INCLUDE EXCLUDE PATTERN
// INCLUDE EXCLUDE PATTERN

#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// revision 1

void print(string str, string output, int i)
{
    if (i >= str.length())
    {
        cout << output << " ";
        return;
    }

    // include
    output.push_back(str[i]);
    print(str, output, i + 1);
    output.pop_back();

    // exclude
    print(str, output, i + 1);
}

int main()
{
    string str = "abc";
    string output = "";
    int i = 0;
    print(str, output, i);

    return 0;
}