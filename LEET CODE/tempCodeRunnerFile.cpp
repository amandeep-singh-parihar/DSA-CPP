#include <bits/stdc++.h>
using namespace std;

int maximumWealth(vector<vector<int>> &accounts)
{
    int maxWealth= 0;
    for (const auto &i : accounts)
    {
        int wealth=0;
        for(int amount: i)
        {
            wealth+=amount;
        }
        maxWealth=max(maxWealth,wealth);
    }
    return maxWealth;
}

int main()
{
    vector<vector<int>> accounts = {
        {1, 2, 3},
        {3, 2, 1},
        {4, 5, 6}
    };
    // for (int i = 0; i < 2; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cin >> accounts[i][j];
    //     }
    // }

    cout << maximumWealth(accounts);

    return 0;
}