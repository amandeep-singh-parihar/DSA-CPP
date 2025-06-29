#include <bits/stdc++.h>
using namespace std;

int main()
{
    int size = 99999;
    int Q[size];
    int f = 0, r = 0;
    int choice, data;
    do
    {
        cout << "press 1 for enQ" << endl;
        cout << "press 2 for deQ" << endl;
        cout << "press 3 for diplay" << endl;
        int press;
        cin >> press;
        switch (press)
        {
        case 1:
            if (r == size)
            {
                cout << "Q is full" << endl;
            }
            else
            {
                cout << "enter the element" << endl;
                cin >> data;
                Q[r] = data;
                r++;
            }
            break;
        case 2:
            if (f == r)
            {
                cout << "Q is empty" << endl;
            }
            else
            {
                int del = Q[f];
                Q[f] = -1;
                f++;
                if (f == r)
                {
                    f = 0;
                    r = 0;
                }
                cout << "deleted element is : " << del << endl;
            }
            break;
        case 3:
            if (f == r == -1)
            {
                cout << "empty" << endl;
            }
            else
            {
                for (int i = f; i < r; ++i)
                {
                    cout << " " << Q[i];
                }
                cout<<endl;
            }
            break;
        default:
            cout << "invalid entery" << endl;
        }
        cout << "do you want to continue press 1 and press any for not" << endl;
        cin >> choice;

    } while (choice == 1);

    return 0;
}