// 733. Flood Fill
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// BFS
// TC O(N*M)
// SC O(N*M)
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int n = image.size();
    int m = image[0].size();
    vector<vector<int>> ans = image;    // make a copy vector name ans
    queue<pair<int, int>> q;            // create a queue of {row,col}
    q.push({sr, sc});                   // push in the queue {row,col}
    int original_color = image[sr][sc]; // take the original color of the pixel from where you start
    if (original_color == color)        // if the original color and and given color is same we don't have to fill the color now
        return ans;
    while (!q.empty()) // till the q is not empty
    {
        auto it = q.front(); // take the front of the queue
        q.pop();             // pop it
        int i = it.first;    // take the first element of the front -> row
        int j = it.second;   // take the second element of the front -> col

        if (i > 0 && ans[i - 1][j] == original_color) // if there exists left of "i" and that have the same pixel
        {
            ans[i - 1][j] = color;
            q.push({i - 1, j});
        }
        if (j > 0 && ans[i][j - 1] == original_color) // if there exists up of "j" and that have the same pixel
        {
            ans[i][j - 1] = color;
            q.push({i, j - 1});
        }
        if (i < n - 1 && ans[i + 1][j] == original_color) // if there exists right of "i" and that have the same pixel
        {
            ans[i + 1][j] = color;
            q.push({i + 1, j});
        }
        if (j < m - 1 && ans[i][j + 1] == original_color) // if there down left of "j" and that have the same pixel
        {
            ans[i][j + 1] = color;
            q.push({i, j + 1});
        }
    }
    return ans; // return the ans
}

// DFS
// TC O(N*M)
// SC O(N*M)
void dfs(int row, int col, vector<vector<int>> &ans,
         vector<vector<int>> &image, int color, int delRow[],
         int delCol[], int original_color)
{
    ans[row][col] = color; // mark the row and col of ans as color
    int n = image.size();
    int m = image[0].size();
    for (int i = 0; i < 4; ++i) // now loop on the deltas
    {
        int nrow = row + delRow[i]; // get the next row
        int ncol = col + delCol[i]; // get the next col
        if (
            nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
            image[nrow][ncol] == original_color && // This ensures that the neighboring cell you're trying to flood fill is of the same original color as the starting cell.
            ans[nrow][ncol] != color               // This checks whether the cell has already been colored with the new color.
        )
        /*
        the above if in simple words
        if (
             it's inside the grid &&
             the color is same as the original &&
             we haven’t colored it yet
)
        */
        {
            dfs(nrow, ncol, ans, image, color, delRow, delCol,
                original_color);
        }
    }
}
vector<vector<int>> _floodFill(vector<vector<int>> &image, int sr, int sc,
                               int color)
{
    int original_color = image[sr][sc]; // take the original color of the given pixel
    vector<vector<int>> ans = image;    // create a copy of the image matrix
    int delRow[4] = {-1, 0, 1, 0};      // create the delta Row (up,right,down,left)
    int delCol[4] = {0, 1, 0, -1};      // create the delta Col (up,right,down,left)
    dfs(sr, sc, ans, image, color, delRow, delCol, original_color);
    return ans;
}

int main()
{

    return 0;
}