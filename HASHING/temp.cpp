#include <bits/stdc++.h>
using namespace std;

bool isArithmetic(vector<int>&v,int ll,int rr)
{
    int minN=*min_element(v.begin()+ll,v.begin()+(rr+1));
    int maxN=*max_element(v.begin()+ll,v.begin()+(rr+1));
    int d=maxN-minN;
    if(d==0) return true;
    vector<bool> 

}

vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
{
    int n=r.size();
    vector<bool> ans;
    for(int i=0;i<n;i++)
    {
        int a=l[i],b=r[i];
        vector<int>v;
        for(int j=a;j<=b;j++)
        {
            v.push_back(nums[j]);
        }
        sort(v.begin(),v.end());
        if(isArithmetic(v))
        {
            ans.push_back(true);
        }else{
            ans.push_back(false);
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Sample input
    vector<int> nums = {4, 6, 5, 9, 3, 7};
    vector<int> l = {0, 0, 2};
    vector<int> r = {2, 3, 5};

    // Function call
    vector<bool> result = checkArithmeticSubarrays(nums, l, r);

    // Output the result
    for (bool val : result) {
        cout << (val ? "true" : "false") << " ";
    }
    cout << endl;

    return 0;
}
