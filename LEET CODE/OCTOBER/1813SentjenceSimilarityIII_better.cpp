//921. Minimum Add to Make Parentheses Valid
#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

bool areSentencesSimilar(string s1,string s2)
{
    if(s1.length()<s2.length())
    {
        swap(s1,s2);
    }

    deque<string>d1,d2;
    stringstream ss1(s1);
    stringstream ss2(s2);
    string token;
    while(ss1>>token){
        d1.push_back(token);
    }

    while(ss2>>token)
    {
        d2.push_back(token);
    }
    while(!d1.empty() && !d2.empty() && d1.front()==d2.front())
    {
        d1.pop_front();
        d2.pop_front();
    }

    while(!d1.empty() && !d2.empty() && d1.back()==d2.back())
    {
        d1.pop_back();
        d2.pop_back();
    }

    return d2.empty();
}

int main()
{
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    cout<<areSentencesSimilar(s1,s2);
    return 0;
}