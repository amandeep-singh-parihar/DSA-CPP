// Alien Dictionary
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// TC O(E+V)
// SC O(topo.size())
string findOrder(vector<string> &words)
{
    int n = words.size();        // the total number of words in the dictonary
    vector<vector<int>> adj(26); // lets take the adj list of 26 vertices
    for (int i = 0; i < n - 1; ++i)
    {
        string s1 = words[i];                // take the first string
        string s2 = words[i + 1];            // take the second string
        int len = min(s1.size(), s2.size()); // lets take the minimum one
        bool found = false;                  // lets mark the found as false
        for (int j = 0; j < len; ++j)        // run a loop till len
        {
            if (s1[j] != s2[j]) // now at any moment the two string not equal
            {
                adj[s1[j] - 'a'].push_back(s2[j] - 'a'); // push them into the adj list
                found = true;                            // and mark it as true
                break;                                   // and break
            }
        }
        if (!found && s1.size() > s2.size()) // now if any invalid case like "abc" , "ab" here the first ab is equal to ab of now the found is true and in this case You check true && s1.size()>s2.size(). so this is wrong and must return ""
            return "";
    }

    vector<bool> exists(26, false); // lets take the exists vector of size 26

    for (auto it : words) // lets loop in words
    {
        for (char ch : it)
        {
            exists[ch - 'a'] = true; // the chars which are present mark them true , for example "bacd" b->true,a->true,c->true,d->true
        }
    }

    vector<int> indegree(26, 0); // now make the indegree of 26 with all 0
    for (int i = 0; i < 26; ++i) // now loop till 26
    {
        for (auto it : adj[i]) // now loop in adj
        {
            ++indegree[it]; // increase the indegree
        }
    }

    queue<int> q;
    for (int i = 0; i < 26; ++i)
    {
        if (exists[i] && indegree[i] == 0) // only push the chars which does exists and have indegree = 0
            q.push(i);
    }

    string topo = "";
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo = topo + (char)(node + 'a');
        for (auto it : adj[node])
        {
            --indegree[it];
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    // this is for checking the cycle in the graph
    for (int i = 0; i < 26; ++i)
    {
        if (exists[i] && indegree[i] != 0) // after processing all the nodes if there indegree[i]!=0 and it exists then return ""
        {
            return "";
        }
    }
    return topo;
}

int main()
{

    return 0;
}