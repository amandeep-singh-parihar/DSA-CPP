// 151. Reverse Words in a String
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// use of string stream

// 1 -> Get the words on the basis space " "
// s = "the sky is blue"
// Automatically trims:
// Leading whitespace (spaces, tabs, newlines)
// And stops reading at the next whitespace
string reverseWords(string s)
{
    stringstream ss(s);
    string word;
    vector<string> v;
    while (ss >> word)
    {
        v.push_back(word);
        v.push_back(" ");
    }
    v.pop_back();
    reverse(v.begin(), v.end());
    string ans = "";
    for (auto it : v)
    {
        ans += it;
    }
    return ans;
}

// syntax
// getline(stream, variable_to_store, delimiter);

// on the basis of ",","." and many more use this

int main()
{
    string line = "apple,banana,mango";
    stringstream ss(line);
    string word;
    vector<string> result;

    while (getline(ss, word, ','))
    {
        result.push_back(word);
    }

    // Print all parts
    for (const string &s : result)
    {
        cout << "Word: " << s << endl;
    }

    return 0;
}