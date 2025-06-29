// L19. Rat in A Maze | Backtracking
// Rat in a Maze Problem - I
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

void helper(int i, int j, int n, vector<vector<int>> &vis,
            vector<vector<int>> &mat, vector<string> &ans, string path)
{
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(path);
        return;
    }

    // down
    if (i + 1 < n && !vis[i + 1][j] && mat[i + 1][j] == 1)
    {
        vis[i + 1][j] = 1;
        helper(i + 1, j, n, vis, mat, ans, path + 'D');
        vis[i + 1][j] = 0;
    }
    // left
    if (j - 1 >= 0 && !vis[i][j - 1] && mat[i][j - 1] == 1)
    {
        vis[i][j - 1] = 1;
        helper(i, j - 1, n, vis, mat, ans, path + 'L');
        vis[i][j - 1] = 0;
    }
    // right
    if (j + 1 < n && !vis[i][j + 1] && mat[i][j + 1] == 1)
    {
        vis[i][j + 1] = 1;
        helper(i, j + 1, n, vis, mat, ans, path + 'R');
        vis[i][j + 1] = 0;
    }
    // up
    if (i - 1 >= 0 && !vis[i - 1][j] && mat[i - 1][j] == 1)
    {
        vis[i - 1][j] = 1;
        helper(i - 1, j, n, vis, mat, ans, path + 'U');
        vis[i - 1][j] = 0;
    }
}
vector<string> findPath(vector<vector<int>> &mat)
{
    int n = mat.size();
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    string path = "";
    if (mat[0][0] == 1)
    {
        vis[0][0] = 1;
        helper(0, 0, n, vis, mat, ans, path);
    }
    return ans;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
int delRow[4] = {1, 0, 0, -1}; // D, L, R, U
int delCol[4] = {0, -1, 1, 0}; // D, L, R, U
// the above also passed in the function which is more good but now it is as global to save time 
// of my own.
void helper(int i, int j, int n, vector<vector<int>> &vis,
            vector<vector<int>> &mat, vector<string> &ans, string path)
{
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(path);
        return;
    }

    string dir = "DLRU";
    for (int ind = 0; ind < 4; ++ind)
    {
        int ni = i + delRow[ind];
        int nj = j + delCol[ind];
        if (ni >= 0 && ni < n && nj >= 0 && nj < n && !vis[ni][nj] && mat[ni][nj] == 1)
        {
            vis[i][j] = 1; // no ni,nj becoz they are not explored yet they will explore after the
            // the below function
            helper(ni, nj, n, vis, mat, ans, path + dir[ind]);
            vis[i][j] = 0;
        }
    }
}
vector<string> findPath(vector<vector<int>> &mat)
{
    int n = mat.size();
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    string path = "";
    if (mat[0][0] == 1)
    {
        vis[0][0] = 1;
        helper(0, 0, n, vis, mat, ans, path);
    }
    return ans;
}

int main()
{

    return 0;
}