#include <bits/stdc++.h>
using namespace std;

int cele(vector<vector<int>> arr, int n)
{
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    //appyling elemination method
    while (s.size() >= 2)
    {
        int i = s.top();
        s.pop();
        int j = s.top();
        s.pop();
        if (arr[i][j] == 1)
        {
            // if i knows j -> means i is not a celebrity
            s.push(j);
        }
        else
        {
            // if i do not j ->means j is not a celebrity
            s.push(i);
        }
    }

    int potential = s.top();
    s.pop();
    //checking the rows and cols for the potential candidate
    for (int i = 0; i < n; i++)
    {
        if (i != potential)
        {
            if (arr[i][potential] == 0 || arr[potential][i] == 1)
            {
                return -1;
            }
        }
    }
    return potential;
}

int main()
{
    int rows, cols;
    cout << "enter the rows and cols : ";
    cin >> rows >> cols;
    vector<vector<int>> arr(rows, vector<int>(cols));
    cout << "enter the elements" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> arr[i][j];
        }
    }
    int celebrity = cele(arr, max(rows, cols));

    if (celebrity != -1)
    {
        cout << "The celebrity is person " << celebrity << endl;
    }
    else
    {
        cout << "No celebrity found in the group." << endl;
    }
    return 0;
}