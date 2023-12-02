#include <bits/stdc++.h>
using namespace std;
int main()
{
    queue<int> q;

    q.push(11);
    q.push(15);
    q.push(13);
    q.push(19);

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