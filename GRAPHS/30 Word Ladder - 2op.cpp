#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Approach -> already written in the notebook

// TC O(N∗M∗26)
// SC O(N∗M)
unordered_map<string, int> mpp;
vector<vector<string>> ans;
string b;
void dfs(string word, vector<string> &seq)
{
    if (word == b) // if the word is equal to beginWord it means You start from end and reach to first
    {
        reverse(seq.begin(), seq.end()); // reverse the seq as You are traversing in the reverse direction
        ans.push_back(seq);              // store the seq in the ans
        reverse(seq.begin(), seq.end()); // again reverse the seq because this is recursion and it has to pass the original seq in the end to begin direction
        return;
    }

    int steps = mpp[word];                // gets the steps of the word, steps = 4 in the case of cog (endWord)
    for (int i = 0; i < word.size(); ++i) // till word.size()
    {
        char original = word[i];
        for (char ch = 'a'; ch <= 'z'; ++ch)
        {
            word[i] = ch;
            if (mpp.find(word) != mpp.end() && mpp[word] + 1 == steps) // now it will only matches with log -> 3 and dog -> 3 which is true so take the log -> 3 first
            {
                seq.push_back(word); // put the log in the sequence
                dfs(word, seq);      // call the dfs again for the same
                seq.pop_back();      // pop it on the backtrack
            }
        }
        word[i] = original;
    }
}

// Here below
// mapping the words in the map with the step at they occur according to the algo
// same as the word Ladder - I

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
{
    unordered_set<string> st(wordList.begin(), wordList.end()); // storing the wordList in the set
    queue<string> q;                                            // queue of string
    q.push({beginWord});                                        // push the beginWord in the queue
    st.erase(beginWord);                                        // erase the beginWord from the set
    mpp[beginWord] = 1;                                         // mark the beginWord as 1 in the map
    b = beginWord;
    while (!q.empty()) // till the q is not empty
    {
        string word = q.front(); // take the word from the q
        q.pop();                 // pop it from the queue
        if (word == endWord)     // if the word from the queue is equal to endWord break
            break;
        int steps = mpp[word];                // get the steps of the word
        for (int i = 0; i < word.size(); ++i) // now till the size of word
        {
            char original = word[i]; // now logic of Word Ladder I
            for (char ch = 'a'; ch <= 'z'; ++ch)
            {
                word[i] = ch;
                if (st.find(word) != st.end())
                {
                    mpp[word] = steps + 1;
                    q.push(word);
                    st.erase(word);
                }
            }
            word[i] = original;
        }
    }
    // Now after all the operations if the endWord is in the map it means You travers all and got the endWord
    if (mpp.find(endWord) != mpp.end())
    {
        vector<string> seq;     // vector for storing the sequence
        seq.push_back(endWord); // push the endword as I am starting from the endword to reduce the paths
        dfs(endWord, seq);      // call the dfs
    }
    return ans; // return ans which got filled according to the dfs
}

int main()
{
    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    vector<vector<string>> ans = findLadders(beginWord, endWord, wordList);
    for (auto it : ans)
    {
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}