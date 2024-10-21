//121. Best Time to Buy and Sell Stock
#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

int maxProfit(vector<int>& prices) {
        vector<int>brr(prices.size());
        int maxi=INT_MIN;
        #pragma unroll
        for(int i=prices.size()-1;i>=0;--i)
        {
            brr[i]=max(maxi,prices[i]);
            maxi=max(maxi,prices[i]);
        }
        int maxP=INT_MIN;
        #pragma unroll
        for(int i=0;i<prices.size();++i)
        {
            maxP=max(maxP,brr[i]-prices[i]);
        }
        return maxP;
    }

int main()
{
    vector<int>arr={7,1,5,3,6,4};
    cout<<maxProfit(arr);
    return 0;
}