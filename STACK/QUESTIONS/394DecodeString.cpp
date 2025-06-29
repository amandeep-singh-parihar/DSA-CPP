// 394. Decode String
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

string decodeString(string s)
{
    stack<string> st;
    for (auto ch : s){
        if (ch == ']'){
            string stringToRepeat = "";
            while (!st.empty() && !isdigit(st.top()[0])){
                string top = st.top();
                stringToRepeat += top == "[" ? "" : top;
                st.pop();
            }

            string numericTimes = "";
            while (!st.empty() && isdigit(st.top()[0])){
                numericTimes += st.top();
                st.pop();
            }
            reverse(numericTimes.begin(), numericTimes.end());
            int n = stoi(numericTimes);

            // final
            string currentDecode = "";
            while (n--){
                currentDecode += stringToRepeat;
            }
            st.push(currentDecode);
        }else{
            string temp(1, ch);
            st.push(temp);
        }
    }
    string ans;
    while (!st.empty()){
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    string str;
    cin >> str;
    cout << decodeString(str);
    return 0;
}