// 542. 01 Matrix
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Why not DFS because we want to count the steps in the breadth like if I apply the DFS it go and count in one go and mark the elements according to the one element which may become conflict in the near future.

// MultiSource BFS
// TC O(N*M)
// SC O(N*M)
vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0)); // visted 2D matrix
    vector<vector<int>> dist(n, vector<int>(m, 0));    // the dist matrix which will the ans
    queue<pair<pair<int, int>, int>> q;                // a queue for the cells having 0 according to this question
    // {{row,col},steps} -> {{row number of 0,col number of 0},steps to make it 0(intially 0 steps)}
    // the q is like if there is a 0 at the 0th row and 0th col {{0,0},0}
    // if there is a 0 at the 0th row and 2nd col {{0,2},0}
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (mat[i][j] == 0)
            {
                visited[i][j] = 1;   // mark all the 0s as visited in the visited matrix
                q.push({{i, j}, 0}); // initially push all the 0s to the queue with there row and col
            }
            else // although no need of this
            {
                visited[i][j] = 0; // if the element is not 0 then in the visited matrix mark it as 0
            }
        }
    }

    int delRow[4] = {-1, 0, 1, 0}; // row -> left,up,down,right
    int delCol[4] = {0, 1, 0, -1}; // col -> left,up,down,right

    while (!q.empty()) // till the queue is not empty
    {
        int row = q.front().first.first;  // take the row
        int col = q.front().first.second; // take the col
        int steps = q.front().second;     // take the steps
        q.pop();                          // pop it from the q
        dist[row][col] = steps;           // in the dist matrix put the steps at the row, col

        for (int i = 0; i < 4; ++i)
        {
            int nrow = row + delRow[i]; // this is for the movement
            int ncol = col + delCol[i]; // this if for the movement

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visited[nrow][ncol] == 0)
            {
                visited[nrow][ncol] = 1;           // mark the row, col as visited if it is valid
                q.push({{nrow, ncol}, steps + 1}); // push the row, col in the queue with steps + 1
            }
        }
    }
    return dist; // return the dist matrix
}

int main()
{
    // Example input matrix
    vector<vector<int>> mat = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}};

    // Call the updateMatrix function
    vector<vector<int>> result = updateMatrix(mat);

    // Print the resulting matrix
    cout << "Updated Matrix:" << endl;
    for (const auto &row : result)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}