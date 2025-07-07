#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Connected components ->
int n, m; // n-> nodes , m->edges
void isConnected(vector<vector<int>> &adj)
{
    for (int i = 0; i < m; ++i)
    {
        if (!visited[i])
        {
            traverse(i);
        }
    }
}

int main()
{

    return 0;
}