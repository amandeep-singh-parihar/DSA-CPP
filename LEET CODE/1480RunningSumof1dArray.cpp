#include <bits/stdc++.h>
using namespace std;

vector<int> runningSum(vector<int> &nums)
{
    int intitial = 0;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        intitial += nums[i];
        ans.push_back(intitial);
    }
    return ans;
}

int main()
{
    int n;
    cout << "enter the size : ";
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    vector<int> result = runningSum(nums);
    cout<<"[";
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i];
        if(i<result.size()-1)
        {
            cout<<",";
        }
    }
    cout<<"]";
    return 0;
}