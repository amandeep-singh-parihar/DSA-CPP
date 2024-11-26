#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

//revision needed

void solve(stack<int> &s, int sizeOfStack, int target)
{
    if (s.empty())
    {
        s.push(target);
        return;
    }

    int temp = s.top();
    s.pop();
    solve(s, sizeOfStack, target);
    s.push(temp);
}

void insert_at_bottom(stack<int> &s, int sizeOfStack)
{
    if(s.empty())
    {
        cout<<"Stack is Empty"<<endl;
    }
    int target=s.top();
    s.pop();
    solve(s, sizeOfStack, target);
}

void print(stack<int> &s)
{
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(-100);
    // s.push(40);
    // s.push(50);
    // s.push(60);
    // s.push(70);
    int sizeOfStack = s.size();
    insert_at_bottom(s, sizeOfStack);
    print(s);
    return 0;
}