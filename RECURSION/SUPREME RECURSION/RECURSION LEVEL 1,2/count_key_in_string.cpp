// count key in the string
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// revision 1

void CountKey(string str, int n, int i, char key, int &count)
{
    // bc
    if (i > n - 1)
    {
        return;
    }

    // 1 case solve
    if (str[i] == key)
    {
        count++;
    }

    CountKey(str, n, i + 1, key, count);
}

int main()
{
    string str = "amandeepsinghparihar";
    int n = str.length();

    int i = 0;
    char key = 'a';
    int count = 0;

    CountKey(str, n, i, key, count);
    cout << count;
    return 0;
}