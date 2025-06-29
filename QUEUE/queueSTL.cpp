#include <bits/stdc++.h>
using namespace std;
int main()
{
    queue<int> q;

    q.push(4);
    q.push(2);
    q.push(3);
    q.push(-1);

    cout<<"************************************"<<endl;

    cout<<"fornt element of the queue is : "<<q.front()<<endl;
    cout<<"fornt element of the queue is : "<<q.back()<<endl;



    cout << "size of queue is : " << q.size() << endl;

    q.pop();

    cout << "size of queue is : " << q.size() << endl;

    q.pop();

    cout << "size of queue is : " << q.size() << endl;

    cout<<"fornt element of the queue is : "<<q.front()<<endl;


    q.pop();

    cout << "size of queue is : " << q.size() << endl;

    q.pop();

    cout << "size of queue is : " << q.size() << endl;

    if(q.empty())
    {
        cout<<"yes";
    }else{
        cout<<"no";
    }


    return 0;
}