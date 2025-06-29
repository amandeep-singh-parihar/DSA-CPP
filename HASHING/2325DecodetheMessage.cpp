#include <bits/stdc++.h>
using namespace std;

string decodeMessage(string key, string message)
{
    map<char, char> mp;
    char temp = 'a';
    for (auto it : key)
    {
        if (it != ' ' && mp.find(it) == mp.end())
        {
            mp[it] = temp;
            temp++;
        }
    }
    string ans = "";
    for (auto it : message)
    {
        if (it != ' ')
        {
            ans += string(1, mp[it]);
            // string(1,mp[it]) it is just creating the string object containing single charter
        }
        else
        {
            ans += " ";
        }
    }
    return ans;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    string key, message;
    getline(cin,key);
    getline(cin,message);//this message is used to take input of when the input have spaces
    cout << decodeMessage(key, message);


    // cout << decodeMessage("the quick brown fox jumps over the lazy dog", "vkbs bs t suepuv");
    return 0;
}