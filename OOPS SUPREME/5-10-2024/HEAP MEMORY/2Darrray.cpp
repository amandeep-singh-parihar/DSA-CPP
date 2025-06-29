#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
int main()
{
    int row, col;
    cin >> row >> col;
    int **arr = new int *[row];
    for (int i = 0; i < row; ++i)
    {
        arr[i] = new int[col];
    }
    cout << endl;
    cout << "*****************" << endl;

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            cin >> arr[i][j];
        }
    }
    cout << "*****************" << endl;
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    //dealocate
    for(int i=0;i<row;++i)
    {
        delete []arr[i];
    }
    delete []arr;
    cout<<endl;
    return 0;
}