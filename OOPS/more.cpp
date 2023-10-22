#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[4][5];
    for(int i=0;i<4;++i){
        for(int j=0;j<5;++j){
            cin>>arr[i][j];
        }
    }

    cout<<"printing the elements"<<endl;
    for(int i=0;i<4;++i){
        for(int j=0;j<5;++j){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    //counting the nonzero elements
    int nonZero=0;
    for(int i=0;i<4;++i){
        for(int j=0;j<5;++j){
            if(arr[i][j]!=0){
                nonZero++;
            }
        }
    }

    //creating the sparse mat
    int sp[nonZero][3];
    int current=1;
    for(int i=0;i<4;++i){
        for(int j=0;j<5;j++){
            if(arr[i][j]!=0){
                sp[current][1]=i;
                sp[current][2]=j;
                sp[current][3]=arr[i][j];
                current++;
            }
        }
    }
    cout<<"printing the sparse matrix"<<endl;
    sp[0][0]=4;
    sp[0][1]=5;
    sp[0][2]=nonZero;
    cout<<sp[0][0]<<" "<<sp[0][1]<<" "<<sp[0][2]<<" "<<endl;
    for(int i=1;i<=nonZero;++i){
        for(int j=1;j<=3;++j){
            cout<<sp[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}