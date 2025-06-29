#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[4]={1,2,4,5};
    char ch[6]="abcde";

    cout<<arr<<endl;//gives address of first block
    cout<<ch<<endl;//print entire array

    char *c=&ch[0];
    cout<<c<<endl;//print entire array


    //TO BE CONTINUED
    return 0;
}