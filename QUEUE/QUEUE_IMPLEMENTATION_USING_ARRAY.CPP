// *************************IMPLEMENTATION OF USING ARRAY*****************************
#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int *arr;
    int f;
    int r;
    int size;

public:
    Queue()
    {
        size = 9999999;
        arr = new int[size];
        f = 0;
        r = 0;
    }

    bool isEmpty()
    {
        return f == r;
    }

    void enqueue(int data)
    {
        if (r == size)
        {
            cout << "Queue is full";
        }
        else
        {
            arr[r] = data;
            r++;
        }
    }

    int dequeue()
    {
        if (f == r)
        {
            return -1;
        }
        else
        {
            int del = arr[f];
            arr[f] = -1;
            f++;
            if (f == r)
            {
                f = 0;
                r = 0;
            }
            return del;
        }
    }
    int front()
    {
        if (f == r)
        {
            return -1;
        }
        else
        {
            return arr[f];
        }
    }

    void display()
    {
        for (int i = f; i < r + 1; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    // Create a Queue object
    Queue myQueue;

    // Enqueue some elements
    myQueue.enqueue(12);
    myQueue.enqueue(2310);
    myQueue.enqueue(3150);
    myQueue.enqueue(3100);

    // Display the front element
    cout << "Front element: " << myQueue.front() << endl;

    // Dequeue an element
    // int removedElement = myQueue.dequeue();
    cout << "Dequeued element: " << myQueue.dequeue() << endl;

    // Display the front element after dequeue
    cout << "front element: " << myQueue.front() << endl;

    // Check if the queue is empty
    if (myQueue.isEmpty())
    {
        cout << "Queue is empty." << endl;
    }
    else
    {
        cout << "Queue is not empty." << endl;
    }

    myQueue.display();

    return 0;
}