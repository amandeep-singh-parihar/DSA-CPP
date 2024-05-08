#include<bits/stdc++.h>
using namespace std;

int numJewelsInStones(string jewels, string stones){
    int hash[256]={0};
    int count=0;
    for(int i=0;i<stones.size();i++)
    {
        hash[stones[i]]++;
    }
    
    for(int i=0;i<jewels.size();i++)
    {
        count+=hash[jewels[i]];
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string jewels,stones;
    cin>>jewels>>stones;
    cout<<numJewelsInStones(jewels,stones);
    return 0;
}