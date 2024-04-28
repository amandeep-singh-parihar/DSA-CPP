#include <bits/stdc++.h>
using namespace std;

vector<int> findWordsContaining(vector<string> &words, char x) {
    vector<int> ans;
    for (int i = 0; i < words.size(); i++) {
        if (words[i].find(x) != string::npos) {
            ans.push_back(i);
        }
    }
    return ans;
}

//agar find ko koi bhi string ya charrecter nahi milta hai to wo fir return krta hai string::npos ye hai string no position jo ki ek non zero value hoti hai iska matlab hai ki bina iske hamara if wala block hamesha true value return karega now word[i].find(x)!=string::npos laga k agar char ya string nahi found hua to wo return karega string::npos and then wo equal hoga string::npos k then condition false hogi and we got the correct answer.

int main()
{
    vector<string>words={"abc","bcd","aaaa","cbc"};
    char x;
    cin>>x;
    vector<int>ans=findWordsContaining(words,x);
    cout<<"[";
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i];
        if(i<ans.size()-1)
        {
            cout<<",";
        }
    }
    cout<<"]";
    return 0;
}