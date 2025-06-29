#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

int solve(string str,char key,int i)
{
    //base case
    if(i<0) return -1;

    //processing
    if(str[i]==key)
    {
        return i;
    }
    return solve(str,key,i-1);
}

int main()
{
    string str="abbcdeddg";
    char key='z';
    int n=str.size();
    int i=n-1;
    cout<<"The index of "<<"'"<<key<<"'"<<" is at : "<<solve(str,key,i);
    return 0;
}