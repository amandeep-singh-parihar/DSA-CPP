// Floyd Warshall
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

void shortestDistance(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (matrix[i][j] == -1)
                matrix[i][j] = 1e9;
            if (i == j)
                matrix[i][j] = 0;
        }
    }

    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    // If want to check the negative cycle
    // for(int i = 0;i<n;++i){
    //     if(matrix[i][i]<0) cout<<"Negative cycle";
    // }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (matrix[i][j] == 1e9)
                matrix[i][j] = -1;
        }
    }
}

int main()
{

    return 0;
}