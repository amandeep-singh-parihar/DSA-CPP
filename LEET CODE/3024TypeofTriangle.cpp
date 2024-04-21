#include <bits/stdc++.h>
using namespace std;

bool isValidTriangle(vector<int> &nums)
{
    int a = nums[0], b = nums[1], c = nums[2];
    return a + b > c && b + c > a && a + c > b;
}

string triangleType(vector<int> &nums)
{
    int a = nums[0], b = nums[1], c = nums[2];
    if (!isValidTriangle(nums))
        return "none";

    if(a==b && b==c)
    {
        return "equilateral";
    }else if(a==b||b==c||a==c)
    {
        return "ispsceles";
    }else{
        return "scalene";
    }
}

int main()
{
    vector<int>nums(3);
    for(int i=0;i<3;i++)
    {
        cin>>nums[i];       
    }

    cout<<triangleType(nums);

    return 0;
}