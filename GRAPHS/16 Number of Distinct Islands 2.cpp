// Number of Distinct Islands
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// pending

int n, m;
int delRow[4] = {-1, 0, 1, 0};
int delCol[4] = {0, 1, 0, -1};

void dfs(int row, int col, vector<vector<int>> &grid, vector<pair<int, int>> &shape, int baseRow, int baseCol)
{
    grid[row][col] = 0;
    shape.push_back({row - baseRow, col - baseCol});
    for (int i = 0; i < 4; ++i)
    {
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1)
        {
            dfs(nrow, ncol, grid, shape, baseRow, baseCol);
        }
    }
}

vector<pair<int, int>> normalize(vector<pair<int, int>> &shape)
{
    vector<vector<pair<int, int>>> forms(8);
    for (auto it : shape)
    {
        int x = it.first;
        int y = it.second;
        forms[0].push_back({x, y});
        forms[1].push_back({x, -y});
        forms[2].push_back({-x, y});
        forms[3].push_back({-x, -y});
        forms[4].push_back({y, x});
        forms[5].push_back({y, -x});
        forms[6].push_back({-y, x});
        forms[7].push_back({-y, -x});
    }

    // cout<<"forms"<<endl;
    // cout<<"forms"<<endl;
    // cout<<"forms"<<endl;
    // for(auto it : shape){
    //     cout<<it.first<<" "<<it.second<<" "<<endl;
    // }
    // cout<<"forms"<<endl;
    // cout<<"forms"<<endl;
    // cout<<"forms"<<endl;

    for (auto &f : forms)
    {
        sort(f.begin(), f.end());
        // normalize by shifting to origin (0, 0)
        int baseX = f[0].first;
        int baseY = f[0].second;
        for (auto &p : f)
        {
            p.first -= baseX;
            p.second -= baseY;
        }
    }

    // cout << "forms" << " endl" << endl;
    // for (auto it : forms)
    // {
    //     for (auto i : it)
    //     {
    //         cout << "(" << i.first << "," << i.second << ")";
    //     }
    //     cout << endl;
    //     cout << "forms" << " endl" << endl;
    // }
    // Return the lex smallest transformation

    sort(forms.begin(), forms.end());
    return forms[0];
}

int countDistinctIslands2(vector<vector<int>> &grid)
{
    n = grid.size();
    m = grid[0].size();
    set<vector<pair<int, int>>> shapes;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] == 1)
            {
                vector<pair<int, int>> shape;
                dfs(i, j, grid, shape, i, j);
                shapes.insert(normalize(shape));
            }
        }
    }

    return shapes.size();
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> grid[i][j];
        }
    }
    cout << countDistinctIslands2(grid);
    return 0;
}

/*

4 5
1 1 1 0 0
1 0 0 0 1
0 1 0 0 1
0 1 1 1 0

shape = {(0,0),(0,1),(0,2),(1,0)}; for the first island
forms =>
{
    { (0,0),(0,1),()}
    { (0,0),(0,-1),()}
    { (0,0),(0,1),()}
    { (0,0),(),()}
    { (0,0),(),()}
    { (0,0),(),()}
    { (0,0),(),()}
    { (0,0),(),()}


}

*/