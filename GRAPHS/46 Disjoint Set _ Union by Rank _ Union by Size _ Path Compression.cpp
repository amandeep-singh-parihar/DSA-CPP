// Disjoint set Union
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; ++i)
        {
            parent[i] = i;
        }
    }

    int findUPar(int node) // this function find the ultimate parent of the given node
    {
        if (node == parent[node]) // if the node is the parent of itself it means it is the ultimate parent
        {
            return node; // return that node
        }
        return parent[node] = findUPar(parent[node]); // or call recursivly
    }

    void unionByRank(int u, int v) // this function union on the basis of rank
    {
        int ulp_u = findUPar(u); // find the ultimate parent of u
        int ulp_v = findUPar(v); // find the ultimate parent of v
        if (ulp_u == ulp_v)      // if the both the ultimate parent if same return
            return;

        if (rank[ulp_u] < rank[ulp_v]) // if the rank of v is larger
        {
            parent[ulp_u] = ulp_v; // now the ultimate parent of u will be ultimate parent of v
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u; // now the ultimate parent of v will be ultimate parent of u
        }
        else
        {
            parent[ulp_v] = ulp_u; // else both equal then assign anyone to anyone
            rank[ulp_u]++;         // increase the rank
        }
    }

    void unionBySize(int u, int v) // this function union on the basis of size
    {
        int ulp_u = findUPar(u); // find the ultimate parent of u
        int ulp_v = findUPar(v); // find the ultimate parent of v
        if (ulp_u == ulp_v)      // if both have the same ultimate parent then return
            return;

        if (size[ulp_u] < size[ulp_v]) // if the size of ultimate parent of u is smaller then the uptimate parent of v
        {
            parent[ulp_u] = ulp_v;      // now the ultimate paernt of u will be ultimate parent of v
            size[ulp_v] += size[ulp_u]; // increase the size of ultimate parent of v by size of ultimate parent of u
        }
        else
        {
            parent[ulp_v] = ulp_u;      // now the ultimate paernt of v will be ultimate parent of u
            size[ulp_u] += size[ulp_v]; // increase the size of ultimate parent of u by size of ultimate parent of v
        }
    }
};
int main()
{
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    if (ds.findUPar(3) == ds.findUPar(7))
    {
        cout << "Same\n";
    }
    else
    {
        cout << "Not Same\n";
    }
    ds.unionBySize(3, 7);
    if (ds.findUPar(3) == ds.findUPar(7))
    {
        cout << "Same\n";
    }
    else
    {
        cout << "Not Same\n";
    }
    return 0;
}