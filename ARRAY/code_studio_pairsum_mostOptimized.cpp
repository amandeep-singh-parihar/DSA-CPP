//most optimized code with the time complexity of O(klogk)
#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> findPairsWithSum(const vector<int> &arr,int targetSum)
{
    unordered_set<int> complementset;
    vector<pair<int,int>> result;

    for(int num:arr)
    {
        int complement=targetSum-num;
        
        if(complementset.count(complement)>0)
        {
            result.push_back(make_pair(min(num,complement),max(num,complement)));
        }
        complementset.insert(num);
    }
    return result;
}

int main()
{
    vector<int> arr = {2, 3, 4, 5, 6, 7};
    int targetSum = 10;

    vector<pair<int, int>> result = findPairsWithSum(arr, targetSum);

    if (!result.empty())
    {
        sort(result.begin(), result.end());
        cout << "Pairs found with the given sum:" << endl;
        for (const auto &pair : result)
        {
            cout <<"[" <<pair.first << ", " << pair.second<<"]"<< endl;
        }
    }
    else
    {
        cout << "No pair found with the given sum." << endl;
    }

    return 0;
}