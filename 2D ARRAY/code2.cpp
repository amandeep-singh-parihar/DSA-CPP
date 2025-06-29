#include <bits/stdc++.h>
using namespace std;

int findMax(vector<vector<int>> &grid, int x, int y)
{
    int maxi = 0;
    for (int i = x; i < x + 3; i++)
    {
        for (int j = y; j < y + 3; j++)
        {
            maxi = max(maxi, grid[i][j]);
        }
    }
    return maxi;
}

vector<vector<int>> largestLocal(vector<vector<int>> &grid)
{
    int n=grid.size();
    vector<vector<int>>maxLocal(n-2,vector<int>(n-2,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            maxLocal[i][j]=findMax(grid,i,j);
        }
    }
    return maxLocal;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}