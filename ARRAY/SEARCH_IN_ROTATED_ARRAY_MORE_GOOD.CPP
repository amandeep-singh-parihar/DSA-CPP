#include<bits/stdc++.h>
using namespace std;

int searchRotatedArray(vector<int> &arr,int target)
{
    int s=0,e=arr.size()-1;
    while(s<=e)
    {
        int mid=s+(e-s)/2;

        if(arr[mid]==target) return mid;

        if(arr[s]<=arr[mid])
        {
            if(arr[s]<=target && target<arr[mid])
            {
                e=mid-1;
            }else{
                s=mid+1;
            }
        }else{
            if(arr[mid]<target && target<=arr[e])
            {
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
    }
    return -1;
}

int main() {
    // Example usage with the provided rotated array
    vector<int> rotatedArray = {9, 10, 11, 1, 2, 3, 4, 5};
    int target;
    cin>>target;

    int result = searchRotatedArray(rotatedArray, target);

    if (result != -1) {
        cout << "Element " << target << " found at index " << result << endl;
    } else {
        cout << "Element " << target << " not found in the array" << endl;
    }

    return 0;
}