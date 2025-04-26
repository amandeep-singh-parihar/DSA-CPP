// 242. Valid Anagram
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// TC O(N+N)
// SC O(26+26) = O(1)
bool isAnagram(string s, string t)
{
    if (s.size() != t.size())
        return false;
    vector<int> sV(26, 0);
    vector<int> tV(26, 0);
    for (int i = 0; i < s.size(); ++i)
    {
        ++sV[s[i] - 'a'], ++tV[t[i] - 'a'];
    }
    for (int i = 0; i < sV.size(); ++i)
    {
        if (sV[i] != tV[i])
            return false;
    }
    return true;
}

// TC O(N+N)
// SC O(26) 
bool _isAnagram(string s, string t)
{
    if(s.size()!=t.size()) return false;
    vector<int>hash(26,0);
    for(int i =0;i<s.size();++i){
        ++hash[s[i]-'a'];
    }
    for(int i =0;i<s.size();++i){
        if(--hash[s[i]-'a']<0) return false;
    }
    return true;
}

int main()
{

    return 0;
}