// 151. Reverse Words in a String
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// TC O(N+N+N) = O(3N) = O(N)
// SC O(N)
string reverseWords(string s)
{
    int n = s.size();
    int i = 0, j = n - 1;
    while (i < n && s[i] == ' ')
    {
        ++i;
    }
    while (j > i && s[i] == ' ')
    {
        --j;
    }
    string str = s.substr(i, j - i + 1);
    stringstream ss(s);
    string word = "";
    vector<string> words;
    while (ss >> word)
    {
        words.push_back(word);
    }
    reverse(words.begin(), words.end());
    string res = "";
    for (auto it : words)
    {
        res += it + " ";
    }
    if (!res.empty())
        res.pop_back();

    return res;
}

int main()
{
    string s = "a good   example";
    cout<<reverseWords(s);
    return 0;
}