// 130. Surrounded Regions
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Intuition->
/* in this question it is said that You have to mark the O to X if it is completly surronded by the
X or not.

like in the example

-> So what I will do, lets start from the boundry of the board, first row,last row, first col,last col
-> and got any O then convert it into anything like '#' now also run the dfs from this point
-> if it is connect to anyone mark it also '#' as the also will run in DFS (DEPTH)
-> after all the operations done You travers the whole array again and convert the board[i][j]=='#'
into board[i][j] = 'O' and the rest to 'X'
simple.

Also be done using Visited

*/

// TC O(N) + O(M) + O(N*M) = O(N*M)
//     for +  for  + dfs
// SC O(N*M)
void dfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>> &board, int n, int m, int delRow[4], int delCol[4])
{
    visited[row][col] = 1;

    for (int i = 0; i < 4; ++i)
    {
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && board[nrow][ncol] == 'O')
        {
            dfs(nrow, ncol, visited, board, n, m, delRow, delCol);
        }
    }
}

void solve(vector<vector<char>> &board)
{
    int n = board.size();
    int m = board[0].size();
    int delRow[4] = {-1, 0, 1, 0};
    int delCol[4] = {0, 1, 0, -1};
    vector<vector<int>> visited(n, vector<int>(m, 0));
    // traverse the first and last row
    for (int j = 0; j < m; ++j)
    {
        // first row
        if (!visited[0][j] && board[0][j] == 'O')
        {
            dfs(0, j, visited, board, n, m, delRow, delCol);
        }
        // last row
        if (!visited[n - 1][j] && board[n - 1][j] == 'O')
        {
            dfs(n - 1, j, visited, board, n, m, delRow, delCol);
        }
    }

    // traverse the first and last col
    for (int i = 0; i < n; ++i)
    {
        // first col
        if (!visited[i][0] && board[i][0] == 'O')
        {
            dfs(i, 0, visited, board, n, m, delRow, delCol);
        }
        // last col
        if (!visited[i][m - 1] && board[i][m - 1] == 'O')
        {
            dfs(i, m - 1, visited, board, n, m, delRow, delCol);
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (!visited[i][j] && board[i][j] == 'O')
            {
                board[i][j] = 'X';
            }
        }
    }
}

int main()
{
    // input
    /*
    4 4
    X X X X
    X O O X
    X X O X
    X O X X

    */

    // output should be
    /*
    X X X X
    X X X X
    X X X X
    X O X X
    */

    int n, m;
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
        }
    }

    solve(board);
    cout << "*******************************" << endl;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
