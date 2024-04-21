#include <bits/stdc++.h>
using namespace std;

vector<int> getConcatenation(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        nums.push_back(nums[i]);
    }
    return nums;
}

int main()
{
    int size;
    cout << "enter the size : ";
    cin >> size;
    vector<int> nums(size);
    cout << "enter the element of nums : ";
    for (int i = 0; i < size; i++)
    {
        cin >> nums[i];
    }

    vector<int> ans = getConcatenation(nums);
    cout<<"[";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
        if(i<nums.size()-1)
        {
            cout<<",";
        }
        
    }
    cout<<"]";

    return 0;
}