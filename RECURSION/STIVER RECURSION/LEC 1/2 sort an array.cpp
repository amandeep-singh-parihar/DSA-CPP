// sort an array using recursion
#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

void insert_sorted(vector<int>&arr,int ele){
    if(arr.empty() || arr[arr.size()-1]<=ele){
        arr.push_back(ele);
        return;
    }

    int last_ele = arr[arr.size()-1];
    arr.pop_back();
    insert_sorted(arr,ele);
    arr.push_back(last_ele);
}

void sortArray(vector<int>&arr){
    if(arr.empty()){
        return;
    }

    int temp = arr[arr.size()-1];
    arr.pop_back();
    sortArray(arr);
    insert_sorted(arr,temp);

}

int main()
{
    vector<int>arr={3,2,1,14,-100,5};
    sortArray(arr);
    for(int i =0;i<arr.size();++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}