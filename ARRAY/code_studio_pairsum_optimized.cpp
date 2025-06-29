//pair sum in the array
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    vector<vector<int>> ans;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] + arr[j] == s)
            {
                vector<int> temp;
                temp.push_back(min(arr[i], arr[j]));
                temp.push_back(max(arr[i], arr[j]));
                ans.push_back(temp);
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
    vector<int> arr = {2, 3, 4, 5, 6, 7}; // Replace this with your own input array
    int targetSum = 10;                   // Replace this with your desired target sum

    vector<vector<int>> result = pairSum(arr, targetSum);

    cout << "Pairs with a sum of " << targetSum << " are:" << endl;
    for (const vector<int> &pair : result)
    {
        cout << "[" << pair[0] << "," << pair[1] << "]" << endl;
    }

    return 0;
}
