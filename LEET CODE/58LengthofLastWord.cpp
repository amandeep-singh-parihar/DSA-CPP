//58. Length of Last Word
#include <bits/stdc++.h>
using namespace std;

int lengthOfLastWord(string s)
{
    int n = s.length() - 1;
    while (s[n] == ' ')
        n--;
    int count = 0;
    while (n >= 0 && s[n] != ' ')
    {
        n--;
        count++;
    }
    return count;
}

int main()
{
    string str="      what     the  heck is this           ";
    cout<<lengthOfLastWord(str);
    return 0;
}