#include <bits/stdc++.h>
using namespace std;

void solve(stack<int>& inputStack, int count, int size)
{
    if (count == (size / 2))
    {
        inputStack.pop();
        return;
    }

    int num = inputStack.top();
    inputStack.pop();
    solve(inputStack, count + 1, size);
    inputStack.push(num);
}

void delete_Middle(stack<int>& inputStack, int size)
{
    int count = 0;
    solve(inputStack, count, size);
}

int main()
{
    stack<int> inputStack;
    inputStack.push(1);
    inputStack.push(2);
    inputStack.push(3);
    inputStack.push(4);
    // inputStack.push(5);

    int size = inputStack.size();

    cout << "Stack contents before deleting the middle element:" << endl;
    stack<int> tempStack = inputStack;
    while (!tempStack.empty())
    {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << endl;

    delete_Middle(inputStack, size);

    cout << "Stack contents after deleting the middle element:" << endl;
    while (!inputStack.empty())
    {
        cout << inputStack.top() << " ";
        inputStack.pop();
    }
    cout << endl;

    return 0;
}