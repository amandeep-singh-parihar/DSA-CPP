#include <bits/stdc++.h>
using namespace std;

class circularQUEUE
{
    int *arr;
    int front, rear;
    int size;

public:
    circularQUEUE()
    {
        static const int size = 99999999;
        arr = new int[size];
        front = rear = -1;
    }

    bool isempty()
    {
        return front == -1 && rear == -1;
    }

    bool isfull()
    {
        return front == (rear + 1) % size;
    }

    void enqueue(int value)
    {
        if (isfull())
        {
            cout << "queue is full" << endl;
            return;
        }
        else if (isempty())
        {
            front = 0;
        }
        rear = (rear + 1) % size;
        arr[rear] = value;
    }

    int dequeue()
    {
        if (front == -1)
        {
            throw exception();
        }
        int res = arr[front];
        if (front == rear)
        {
            front = rear - 1;
        }
        else
        {
            front = (front + 1) % size;
        }
        return res;
    }

    void display()
    {
        int i = front;
        do
        {
            cout << arr[i] << " ";
            i = (i + 1) % size;
        } while (i != (rear + 1) % size);
    }
};

int main()
{
    circularQUEUE q;

    q.enqueue(15);
    q.enqueue(31);
    q.enqueue(-1);
    q.enqueue(-123);
    q.enqueue(123);
    q.enqueue(159999);
    q.enqueue(1020);
    q.enqueue(20);

    q.display();
    cout<<endl;

    cout<<"deleted element is : "<<q.dequeue()<<endl;
    cout<<"deleted element is : "<<q.dequeue()<<endl;
    cout<<"deleted element is : "<<q.dequeue()<<endl;
    cout<<"deleted element is : "<<q.dequeue()<<endl;


    q.display();

    return 0;
}