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
    int size;
    int top1;
    int top2;

    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top1 = -1;
        top2 = size;

        // to see the working of the stack (No need of this)
        fill(arr, arr + size, 0);
    }

    void push1(int data)
    {
        if (top2 - top1 == 1)
        {
            // space not available
            cout << "OverFlow in Stack 1" << endl;
        }
        else
        {
            ++top1;
            arr[top1] = data;
        }
    }
    void push2(int data)
    {
        if (top2 - top1 == 1)
        {
            // space not available
            cout << "OverFlow in Stack 2" << endl;
        }
        else
        {
            --top2;
            arr[top2] = data;
        }
    }

    void pop1()
    {
        if (top1 == -1)
        {
            cout << "Stack Underflow in Stack 1" << endl;
        }
        else
        {
            --top1;
        }
    }

    void pop2()
    {
        if (top2 == size)
        {
            cout << "Stack Underflow in Stack 2" << endl;
        }
        else
        {
            ++top2;
        }
    }

    void print()
    {
        cout << endl;
        cout << "top1 : " << top1 << endl;
        cout << "top2 : " << top2 << endl;
        for (int i = 0; i < size; ++i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack s(10);

    s.push1(10);
    s.print();
    s.push1(20);
    s.print();
    s.push1(30);
    s.print();
    s.push1(40);
    s.print();
    s.push1(50);
    s.print();
    s.push1(60);
    s.print();

    s.push2(100);
    s.print();
    s.push2(200);
    s.print();
    s.push2(300);
    s.print();
    s.push2(400);
    s.print();
}