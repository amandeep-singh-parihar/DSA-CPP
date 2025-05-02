// 451. Sort Characters By Frequency
#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

string frequencySort(string s) {
    unordered_map<char, int> mp;
    for (auto it : s) {
        mp[it]++;
    }
    priority_queue<pair<int, char>> q;
    for (auto it : mp) {
        q.push({it.second, it.first});
    }
    string res = "";
    while (!q.empty()) {
        auto top = q.top();
        q.pop();
        int cnt = top.first;
        char ch = top.second;
        res.append(cnt, ch);
    }
    return res;
}

int main()
{
    string s = "tree";
    cout<<frequencySort(s);  
    return 0;
}