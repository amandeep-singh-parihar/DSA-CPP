// L9. Combination Sum II | Leetcode | Recursion | Java | C++
// 40. Combination Sum II
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Brute -> simply take all the possible combination
// in the end push the vector in the set of vector and convert the set as vector and return
// MLE
// TC O(2^n * klog(setSize))
// SC O(k * x) x = number of unique combinations in the result
void helper(int i, vector<int> &c, int t, vector<vector<int>> &ans,
            vector<int> &output)
{
    if (i == c.size())
    {
        if (t == 0)
        {
            ans.push_back(output);
        }
        return;
    }

    // include
    if (c[i] <= t)
    {
        output.push_back(c[i]);
        helper(i + 1, c, t - c[i], ans, output);
        output.pop_back();
    }

    // exclude
    helper(i + 1, c, t, ans, output);
}
vector<vector<int>> combinationSum2(vector<int> &c, int t)
{
    sort(c.begin(), c.end());
    vector<vector<int>> ans;
    vector<int> output;
    helper(0, c, t, ans, output);
    set<vector<int>> myAns(ans.begin(), ans.end());
    return vector<vector<int>>(myAns.begin(), myAns.end());
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

void helper(int ind, vector<vector<int>> &ans, vector<int> &ds,
            vector<int> &candidates, int target)
{
    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }

    for (int i = ind; i < candidates.size(); ++i)
    {
        if (i != ind && candidates[i] == candidates[i - 1])
            continue;
        // the condition above mean we do not pick the number at the same level of recursion
        // to avoid duplicate if the i running loop is greater than ind it mean we are at the
        // same level just in the loop for the rest element of the array
        // there i != ind and the current is equal to the previous element there we skip that
        // exam [1,1,1,2]
        // here recursion make four calls for the array
        // initially at Level 0 we pick 1 and the for (2), (3) call we don't pick 1 as this make
        // duplicate but the ans must have [1,1,2] if target is 4 HOW?
        // the ans is when the Level 1 recursion done We reach at level 2 now we have index as 1
        // now Three recursion calls we have not four one less now
        // now i=ind=1 i can pick 1 make the ds [1,1] but i don't take the 1 which is at index 2
        // and have the recursion call number (2) for this level
        if (candidates[i] > target)
            break;
        ds.push_back(candidates[i]);
        helper(i + 1, ans, ds, candidates, target - candidates[i]);
        ds.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> ds;
    helper(0, ans, ds, candidates, target);
    return ans;
}

int main()
{

    return 0;
}