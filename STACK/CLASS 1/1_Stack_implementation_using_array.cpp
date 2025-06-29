#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

class Stack
{
public:
    int *arr;
    int top;
    int size;

    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top = -1;
    }

    void push(int data)
    {
        if (size - top > 1)
        {
            ++top;
            arr[top] = data;
        }
        else
        {
            // Stack overflow
            cout << "Stack OverFlow" << endl;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
        }
        else
        {
            --top;
        }
    }

    int getTop()
    {
        if (top == -1)
        {
            cout << "No element in the Stack" << endl;
        }
        else
        {
            return arr[top];
        }
    }

    // number of valid elements in the Stack
    int getSize()
    {
        return top + 1;
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }
};

int main()
{

    Stack s(10);

    // insertion
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout << s.getTop() << endl;

    // while (!s.isEmpty())
    // {
    //     cout << s.getTop() << endl;
    //     s.pop();
    // }

    cout << endl;
    cout << s.getSize() << endl;

    return 0;
}