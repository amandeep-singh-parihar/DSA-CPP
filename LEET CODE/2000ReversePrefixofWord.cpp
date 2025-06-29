#include <bits/stdc++.h>
using namespace std;

string reversePrefix(string word, char ch)
{
    int i=0,j=word.find(ch);
    while(i<j)
    {
        swap(word[i],word[j]);
        i++,j--;
    }
    return word;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string word;
    cin>>word;
    char ch;
    cin>>ch;
    cout<<reversePrefix(word,ch);
    return 0;
}