// 2825. Make String a Subsequence Using Cyclic Increments
#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

bool canMakeSubsequence(string str1, string str2) {
        int i = 0;
        int j = 0;
        while (i < str1.size() && j < str2.size()) {
            if ((str1[i] == str2[j]) || (str1[i] == 'z' && str2[j] == 'a') ||
                (str1[i] + 1 == str2[j])) {
                ++i, ++j;
            } else {
                ++i;
            }
        }
        return j == str2.size();
    }

int main()
{
    string str1,str2;
    cin>>str1>>str2;
    cout<<canMakeSubsequence(str1,str2);
    return 0;
}