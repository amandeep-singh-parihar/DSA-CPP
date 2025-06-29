// 13. Roman to Integer
#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

int romanToInt(string s) {
    unordered_map<char,int>mp={
        {'I',1},
        {'V',5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    int sum = 0,i=0;
    for(int i =0;i<s.size();++i){
        if(mp[s[i]]<mp[s[i+1]]){
            sum-=mp[s[i]];
        }else{
            sum+=mp[s[i]];
        }
    }
    return sum;
}

int main()
{
    string s = "MCMXCIV";
    // string s = "LVIII";
    // string s = s = "III";
    cout<<romanToInt(s);
    return 0;
}