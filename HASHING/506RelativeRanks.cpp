#include <bits/stdc++.h>
using namespace std;

vector<string> findRelativeRanks(vector<int> &score)
{
    int n = score.size();
    vector<int> cpy(n);
    copy(score.begin(), score.end(), cpy.begin());

    unordered_map<int, int> ranktoIndex(n);
    for (int i = 0; i < n; i++)
    {
        ranktoIndex[cpy[i]] = i;
    }

    sort(cpy.begin(), cpy.end(), greater<int>());

    vector<string> rank(n);
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            rank[ranktoIndex[cpy[i]]] = "Gold Medal";
        else if (i == 1)
            rank[ranktoIndex[cpy[i]]] = "Silver Medal";
        else if (i == 2)
            rank[ranktoIndex[cpy[i]]] = "Bronze Medal";
        else
            rank[ranktoIndex[cpy[i]]] = to_string(i + 1);
    }
    return rank;
}

int main()
{
    // Example input scores
    vector<int> scores = {10, 20, 15, 25, 30};

    // Call the function to find relative ranks
    vector<string> ranks = findRelativeRanks(scores);

    // Output the ranks
    cout << "Ranks:" << endl;
    for (const string &rank : ranks)
    {
        cout << rank << ",";
    }

    return 0;
}