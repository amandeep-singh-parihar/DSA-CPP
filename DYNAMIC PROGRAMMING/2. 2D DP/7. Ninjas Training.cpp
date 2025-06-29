// Ninja’s Training
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Revision 1

// Memoization
// TC O(N*4*3)
// SC O(N) + O(N*4)
int f(int day, int lastTask, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (day == 0) // if the day = 0 it means all the rest day has done
    {
        int maxi = 0;
        for (int task = 0; task <= 2; ++task)
        {
            if (task != lastTask) // the lastTask and task at day 0 not be same
            {
                maxi = max(maxi, points[0][task]); // get the max in the rest tasks
            }
        }
        return maxi;
    }

    // dp check
    if (dp[day][lastTask] != -1)
        return dp[day][lastTask];

    int maxi = 0;
    for (int task = 0; task <= 2; ++task)
    {
        if (task != lastTask)
        {
            int point = points[day][task] + f(day - 1, task, points, dp);
            // get the point at that day and call for the prev day with this task
            maxi = max(maxi, point);
        }
    }
    return dp[day][lastTask] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    int ans = f(n - 1, 3, points, dp); // 3 means no task done yet
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return ans;
}

// Tabulation
// TC O(N*4*3)
// SC O(N*4)
int _ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, 0));
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));
    for (int day = 1; day < n; ++day)
    {
        for (int lastTask = 0; lastTask <= 3; ++lastTask)
        {
            // dp[day][lastTask] = 0;
            for (int task = 0; task <= 2; ++task)
            {
                if (task != lastTask)
                {
                    int point = points[day][task] + dp[day - 1][task];
                    dp[day][lastTask] = max(dp[day][lastTask], point);
                }
            }
        }
    }
    return dp[n - 1][3];
}

// // Space optimization -> pending revision
// // TC O(N*4*3)
// // SC O(4) = O(1)
int __ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> dp(4, -1);
    dp[0] = max(points[0][1], points[0][2]);
    dp[1] = max(points[0][0], points[0][2]);
    dp[2] = max(points[0][0], points[0][1]);
    dp[3] = max(points[0][0], max(points[0][1], points[0][2]));
    for (int day = 1; day < n; ++day)
    {
        vector<int> temp(4, 0);
        for (int lastTask = 0; lastTask <= 3; ++lastTask)
        {
            temp[lastTask] = 0;
            for (int task = 0; task <= 2; ++task)
            {
                if (task != lastTask)
                {

                    temp[lastTask] = max(temp[lastTask], points[day][task] + dp[task]);
                }
            }
        }
        dp = temp;
    }
}

int main()
{
    vector<vector<int>> points = {{10, 40, 70},
                                  {20, 50, 80},
                                  {30, 60, 90}};

    cout << __ninjaTraining(3, points);

    return 0;
}