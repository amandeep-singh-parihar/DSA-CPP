#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// TC O(N) + O(2E)
// SC O(3N)
vector<int> bfsOfGraph(vector<vector<int>> &adj)
{
    int V = adj.size();    // first take the number of nodes
    vector<int> vis(V, 0); // create a vector of size equal to nodes and mark all as 0
    vis[0] = 1;            // mark the 0th index as 1 as if 0 based indexing
    // vis[1] = 1;         // in case of 1 based indexing
    queue<int> q;          // create a queue
    q.push(0);             // push the 0 in the queue
    vector<int> bfs;       // create a vector which store the value of bfs traversal
    while (!q.empty())     // till the q is not empty
    {
        int node = q.front(); // take the front node
        q.pop();              // pop it
        bfs.push_back(node);  // push the node in the bfs vector

        for (auto it : adj[node]) // now check the neighbours of that node in the adjacency list
        {
            if (!vis[it]) // if the neighbours is not visited
            {
                vis[it] = 1; // mark them as visited
                q.push(it);  // and push it in the queue
            }
        }
    }
    return bfs; // return the bfs vector
}

int main()
{

    //     0
    //    / \
    //   1   2
    //  / \  / \
    // 3   4 5  6

    vector<vector<int>> adj = {
        {1, 2},    // Node 0 is connected to 1 and 2
        {0, 3, 4}, // Node 1 is connected to 0, 3, and 4
        {0, 5, 6}, // Node 2 is connected to 0, 5, and 6
        {1},       // Node 3 is connected to 1
        {1},       // Node 4 is connected to 1
        {2},       // Node 5 is connected to 2
        {2}        // Node 6 is connected to 2
    };

    // the graph with 1 based indexing
    // vector<vector<int>> adj = {
    //     {}, // first must be empty as of 0th index
    //     {2, 6},
    //     {1, 3, 4},
    //     {2},
    //     {2, 5},
    //     {4, 8},
    //     {1, 7, 9},
    //     {6, 8},
    //     {5, 7},
    //     {6}
    // };

    vector<int> bfs = bfsOfGraph(adj);

    cout << "BFS Traversal: ";
    for (int node : bfs)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}