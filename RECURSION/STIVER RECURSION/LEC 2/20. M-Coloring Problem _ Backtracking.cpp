// L16. M-Coloring Problem | Backtracking
// M-Coloring Problem
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// TC: O(m^v)
// SC: O(v)

bool isSafe(int node, int col, vector<int> &color, vector<pair<int, int>> &edges)
{
    for (auto it : edges)
    {
        int u = it.first;
        int v = it.second;

        if (u == node && color[v] == col)
            return false;
        if (v == node && color[u] == col)
            return false;
    }

    return true;
}

bool helper(int node, int v, vector<pair<int, int>> &edges, int m, vector<int> &color)
{
    if (node == v)
    {
        return true;
    }

    for (int col = 1; col <= m; ++col)
    {
        if (isSafe(node, col, color, edges))
        {
            color[node] = col;
            if (helper(node + 1, v, edges, m, color))
                return true;
            color[node] = 0;
        }
    }

    return false;
}

bool graphColoring(int v, vector<pair<int, int>> &edges, int m)
{
    vector<int> color(v, 0);
    return helper(0, v, edges, m, color);
}

int main() {
    int v = 4; // number of vertices
    int m = 3; // number of colors
    vector<pair<int, int>> edges = {
        {0, 1}, {1, 2}, {2, 3}, {3, 0}, {0, 2}
    };

    if (graphColoring(v, edges, m))
        cout << "1\n"; // Coloring possible
    else
        cout << "0\n"; // Not possible

    return 0;
}
