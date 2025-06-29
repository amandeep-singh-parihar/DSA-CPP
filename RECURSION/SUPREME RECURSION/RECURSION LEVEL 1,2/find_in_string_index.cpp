#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
// revision 2
int findKey(string &str, int &i, int &n, char &key)
{
    if (i > n - 1)
    {
        return -1;
    }

    // 1case solve
    if (str[i] == key)
    {
        return i;
    }

    return findKey(str, ++i, n, key);
}

int main()
{
    string str = "amandeepsinghparihar";
    int n = str.length();

    char key = 'r';
    int i = 0;

    int ans = findKey(str, i, n, key);
    cout << "ans is : " << ans;

    return 0;
}