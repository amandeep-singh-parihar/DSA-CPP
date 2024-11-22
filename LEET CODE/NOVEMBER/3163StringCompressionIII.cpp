// 3163. String Compression III
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
#define ll long long
string compressedString(string word)
{
    int n = word.size();
    string res = "";
    int prefix = 1;
    int i = 0;
    while (i < n)
    {
        long long c = 1;
        int j = i;
        while (word[j] == word[j + 1])
        {
            c++;
            ++j;
            ++i;
            if (c == 9)
            {
                break;
            }
        }
        res.push_back('0' + c);
        res.push_back(word[i]);
        ++i;
    }
    return res;
}

int main()
{
    string str;
    cin >> str;
    cout << compressedString(str) << endl;
    return 0;
}