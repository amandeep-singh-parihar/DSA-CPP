#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
//rivise pending
bool isSafe(vector<vector<string>> &board, int row, int col, int n)
{
    int i = row, j = col;
    // row
    while (j--)
    {
        if (board[i][j] == "Q")
        {
            return false;
        }
    }

    // check upper left diagonal
    i = row, j = col;
    while (i-- && j--)
    {
        if (board[i][j] == "Q")
        {
            return false;
        }
    }

    // check bottom left diagonal
    i = row, j = col;
    while (i < n && j >= 0)
    {
        if (board[i][j] == "Q")
        {
            return false;
        }
        i++;
        j--;
    }

    return true;
}

void solve(vector<vector<string>> &board, vector<vector<string>> &result, int col, int n)
{
    // base case
    if (col == n)
    {
        vector<string> solution;
        for (int i = 0; i < n; ++i)
        {
            string row = "";
            for (int j = 0; j < n; ++j)
            {
                row += board[i][j];
            }
            solution.push_back(row);
        }
        result.push_back(solution);
        return;
    }

    //recursion
    for (int row = 0; row < n; ++row)
    {
        if (isSafe(board, row, col, n))
        {
            board[row][col] = "Q";
            solve(board, result, col + 1, n);

            //backtracking
            board[row][col] = ".";
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<string>> board(n, vector<string>(n, "."));
    vector<vector<string>> result;
    solve(board, result, 0, n);
    for (int i = 0; i < result.size(); ++i)
    {
        cout << "[";
        for (int j = 0; j < result[0].size(); ++j)
        { 
            cout<< "[" << '"' << result[i][j] << '"';
            if(j<result[0].size()-1)
            {
                cout<<",";
            }
            cout<<"]";
        }
        cout << "]";
        cout << endl;
        cout << endl;
    }
    cout << endl;
    return 0;
}