//intersection of two arrays by CODE HELP ------------------> *******NOT OPTIMIZED*******

#include<bits/stdc++.h>
using namespace std;
void intersection(int arr[],int brr[],int size1,int size2)
{
    for(int i=0;i<size1;i++)
    {
        for(int j=0;j<size2;j++)
        {
            if(arr[i]==brr[j])
            {
                cout<< arr[i] <<" ";
                brr[j]=INT_MIN;
                break;
            }
        }
    }
}
int main()
{
    int arr[5]={1,1,3,7,7};    
    int brr[6]={2,-12,5,7,3,1};



    intersection(arr,brr,5,6);





    return 0;

}