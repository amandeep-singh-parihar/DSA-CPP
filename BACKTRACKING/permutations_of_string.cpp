#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

void printPermutations(string &str,int i)
{
    if(i>=str.length())
    {
        cout<<str<<endl;
        return;
    }

    for(int j=i;j<str.length();++j)
    {
        swap(str[i],str[j]);
        printPermutations(str,i+1);
        
        //backtrack
        swap(str[i],str[j]);
    }
}

int main()
{
    string str;
    cin>>str;
    cout<<"****************"<<endl;
    printPermutations(str,0);
    cout<<"****************"<<endl;
    return 0;
}