//**********************************CIRCULAR QUEUE**********************************
#include <bits/stdc++.h>
using namespace std;

class circularQUEUE
{
    int *arr;
    int size;
    int front, rear;

public:
    circularQUEUE()
    {
        static const int size = 9999999;
        arr = new int[size];
        front = rear = -1;
    }

    bool isfull()
    {
        return (rear + 1) % size == front;
    }

    bool isempty()
    {
        return front == -1 && rear == -1;
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
        int result = arr[front];
        if (front == rear)//it means that is the first element and after deque the queue will be empty
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
        return result;
    }

    void display()
    {
        if (isempty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
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
    circularQUEUE myqueue;

    // Enqueue some elements
    myqueue.enqueue(15);
    myqueue.enqueue(16);
    myqueue.enqueue(18);
    myqueue.enqueue(20);

    myqueue.display();
    cout<<endl;

    // Dequeue elements
    cout << "Dequeued: " << myqueue.dequeue() << endl;
    cout << "Dequeued: " << myqueue.dequeue() << endl;

    // Enqueue more elements
    myqueue.enqueue(22);
    myqueue.enqueue(24);
    myqueue.display();
    cout<<endl;

    // Dequeue the remaining elements
    while (!myqueue.isempty())
    {
        cout << "Dequeued: " << myqueue.dequeue() << endl;
    }

    return 0;
}
