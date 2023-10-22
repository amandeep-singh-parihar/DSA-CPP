#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> &s, int x)
{
    if (s.empty())
    {
        s.push(x);
        return;
    }

    int num=s.top();
    s.pop();

    solve(s,x);
    s.push(num);
}

stack<int> pushAtBottom(stack<int> &myStack, int x)
{
    solve(myStack, x);
    return myStack;
}

int main() {
    stack<int> myStack;

    // Push some elements onto the stack
    myStack.push(3);
    myStack.push(2);
    myStack.push(1);

    int x; // Element to be pushed at the bottom of the stack
    cout<<"enter the element you want to push at bottom : ";
    cin>>x;
    myStack = pushAtBottom(myStack, x);

    // Print the modified stack
    while (!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }

    return 0;
}