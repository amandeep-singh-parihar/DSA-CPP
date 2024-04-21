#include <bits/stdc++.h>
using namespace std;

vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
{
    int maxCandies=0;
    for(auto candy: candies)
    {
        maxCandies=max(candy,maxCandies);
    }

    vector<bool> ans;
    for(auto candy: candies)
    {
        ans.push_back(candy+extraCandies>=maxCandies);
    }
    return ans;
}

int main()
{
    int n;
    cout<<"enter the size : ";
    cin >> n;
    int extraCandies;
    cout<<"enter the number of extra candies : ";
    cin >> extraCandies;
    vector<int> candies(n);
    for (int i = 0; i < candies.size(); ++i)
    {
        cin >> candies[i];
    }

    vector<bool> ans = kidsWithCandies(candies, extraCandies);
    cout<<"[";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
        if(i<ans.size()-1)
        {
            cout<<",";
        }
        
    }
    cout<<"]";
    return 0;
}