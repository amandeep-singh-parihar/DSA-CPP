// 127. Word Ladder
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    unordered_set<string> st(wordList.begin(), wordList.end());
    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    st.erase(beginWord);
    while (!q.empty())
    {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (word == endWord)
            return steps;

        for (int i = 0; i < word.size(); ++i)
        {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ++ch)
            {
                word[i] = ch;
                if (st.find(word) != st.end())
                {
                    st.erase(word);
                    q.push({word, steps + 1});

                    // also done the below
                    // if (word == endWord)
                    //     return steps + 1;
                }
            }
            word[i] = original;
        }
    }
    return 0;
}

int main()
{

    return 0;
}