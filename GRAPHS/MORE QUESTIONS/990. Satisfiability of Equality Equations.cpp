// 990. Satisfiability of Equality Equations
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
class DisJointSet
{
    vector<int> parent, size;

public:
    DisJointSet()
    {
        parent.resize(26 + 1);
        size.resize(26 + 1, 1);
        for (int i = 0; i < 26 + 1; ++i)
        {
            parent[i] = i;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void UnionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution
{
public:
    bool equationsPossible(vector<string> &equations)
    {
        int n = equations.size();
        DisJointSet ds;
        for (auto it : equations)
        {
            int variable1 = it[0];
            int variable2 = it[3];

            if (it[1] == '=')
            {
                ds.UnionBySize(variable1 - 'a', variable2 - 'a');
            }
        }
        for (auto it : equations)
        {
            int variable1 = it[0];
            int variable2 = it[3];

            if (it[1] == '!')
            {
                if (ds.findUPar(variable1 - 'a') ==
                    ds.findUPar(variable2 - 'a'))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
int main()
{

    return 0;
}