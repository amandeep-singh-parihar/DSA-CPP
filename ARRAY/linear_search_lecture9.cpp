//linear search 
#include<bits/stdc++.h>
using namespace std;
bool ls(int arr[],int size,int key)
{
    for(int i=0;i<size;i++)
    {
        if(key==arr[i])
        {
            return true;
        }
    }
    return false;

}
int main()
{
    int arr[6];
    cout<<"enter the whole array : ";
    for(int i=0;i<6;i++)
    {
        cin>>arr[i];
    }
    int key;
    cout<<"enter the key : ";
    cin>>key;


    bool found=ls(arr,6,key);
    if(found)
    {
        cout<<key<<" is present ";

    }
    else{
        cout<<key<<" is absent";
    }



    return 0;

}