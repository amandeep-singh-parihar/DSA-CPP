// 155. Min Stack
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// revision 1

class MinStack
{
public:
    vector<pair<int, int>> arr;
    MinStack() {}

    void push(int val)
    {
        if (arr.empty())
        {
            pair<int, int> p = make_pair(val, val);
            arr.push_back(p);
        }
        else
        {
            pair<int, int> p;
            p.first = val;
            p.second = min(val, arr.back().second);
            arr.push_back(p);
        }
    }

    void pop() { arr.pop_back(); }

    int top() { return arr.back().first; }

    int getMin() { return arr.back().second; }
};

int main()
{

    return 0;
}