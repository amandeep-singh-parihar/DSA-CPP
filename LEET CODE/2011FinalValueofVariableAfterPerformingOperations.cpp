#include <bits/stdc++.h>
using namespace std;

int finalValueAfterOperations(vector<string> &operations)
{
    int X=0;
    for(int i=0;i<operations.size();i++)
    {
        if(operations[i]=="++X" || operations[i]=="X++")
        {
            X++;
        }else{
            X--;
        }
    }
    return X;
}

int main()
{
    vector<string> s={"X++","++X","--X","X--"};
    cout<<finalValueAfterOperations(s);
    return 0;
}