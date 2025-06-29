//1963. Minimum Number of Swaps to Make the String Balanced
#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

int minSwaps(string s)
{
    int size=0;
    for(auto it:s)
    {
        if(it=='[')
        {
            size++;
        }else if(size>0){
            size--;
        }
    }
    return (s.size()+1)/2;
}

int main()
{
    string s;
    cin>>s;
    cout<<minSwaps(s);
    return 0;
}