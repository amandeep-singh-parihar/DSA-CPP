#include<bits/stdc++.h>
using namespace std;
int main()
{

    // int arr[10]={2,5,7,8};
    // cout<<"address of the first memory block is "<<arr<<endl;//gives address
    // cout<<"address of the first memory block is "<<&arr[0]<<endl;//gives address
    // cout<<"------------------->"<<*arr<<endl;//value of first index
    // cout<<"------------------->"<<*arr+1<<endl;//value of first index + 1
    // cout<<"------------------->"<<*(arr+1)<<endl;//value of 2 index
    // cout<<"------------------->"<<(*arr)+1<<endl;//value of first index + 1
    // cout<<"------------------->"<<arr[3]<<endl;//value of third index
    // cout<<"------------------->"<<*(arr+3)<<endl;//value of third index
    // //arr[i]=*(arr+i)
    // //i[arr]=*(i+arr)
    // cout<<"------------------->"<<1[arr]<<endl;//value of first index
    // cout<<"------------------->"<<*(1+arr)<<endl;//value of first index


    int temp[10]={100,200};
    cout<<"----------->"<<sizeof(temp)<<endl;// 4*10=400
    cout<<"----------->"<<sizeof(&temp)<<endl; //4 byte
    int *ptr=&temp[0];
    cout<<"----------->"<<sizeof(ptr)<<endl; //4 byte
    cout<<"----------->"<<sizeof(*ptr)<<endl; // 4 byte
    cout<<"----------->"<<sizeof(&ptr)<<endl; //





    




    return 0;
}