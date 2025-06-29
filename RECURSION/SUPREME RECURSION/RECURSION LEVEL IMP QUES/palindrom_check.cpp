#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// revision 1

bool solve(string str, int i, int j)
{
    if (i > j)
        return 1;

    // 1 case solve
    if (str[i] != str[j])
        return 0;

    // RE call
    return solve(str, i + 1, j - 1);
}

int main()
{
    string str = "nitin";
    int i = 0;
    int j = str.size() - 1;
    if (solve(str, i, j))
    {
        cout << "The given string " << "'" << str << "'" << " is palindrome" << endl;
    }
    else
    {
        cout << "The given string " << "'" << str << "'" << " is not palindrome" << endl;
    }

    return 0;
}