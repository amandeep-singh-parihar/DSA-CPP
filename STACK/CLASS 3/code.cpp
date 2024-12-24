// // // #include <bits/stdc++.h>
// // // using namespace std;
// // // static const bool __boost = []()
// // // {
// // //     cin.tie(nullptr);
// // //     cout.tie(nullptr);
// // //     return ios_base::sync_with_stdio(false);
// // // }();

// // // vector<int> prevelement(vector<int> &arr, int n)
// // // {
// // //     stack<int> st;
// // //     st.push(-1);
// // //     vector<int> ans(n);
// // //     for (int i = 0; i < n; ++i)
// // //     {
// // //         while (st.top() != -1 && arr[i] <= arr[st.top()])
// // //         {
// // //             st.pop();
// // //         }
// // //         if (st.top() == -1)
// // //         {
// // //             ans[i] = -1;
// // //         }
// // //         else
// // //         {
// // //             ans[i] = st.top();
// // //         }
// // //         st.push(i);
// // //     }
// // //     return ans;
// // // }

// // // vector<int>nextele(vector<int>&arr,int n)
// // // {
// // //     stack<int>s;
// // //     s.push(-1);
// // //     vector<int>ans(n);
// // //     for(int i=n-1;i>=0;--i)
// // //     {
// // //         while(s.top()!=-1 && arr[i]<=arr[s.top()])
// // //         {
// // //             s.pop();
// // //         }
// // //         if(s.top()==-1)
// // //         {
// // //             ans[i]=n;   
// // //         }else{
// // //             ans[i]=s.top();
// // //         }
// // //         s.push(i);
// // //     }
// // //     return ans;
// // // }

// // // int largestRectangleArea(vector<int> &heights)
// // // {
// // //     if (heights.size() == 0)
// // //     {
// // //         return 0;
// // //     }
// // //     vector<int> pse = prevelement(heights, heights.size());
// // //     vector<int> nse = nextele(heights, heights.size());
// // //     int maxi = 0;
// // //     for (int i = 0; i < heights.size(); ++i)
// // //     {
// // //         maxi = max(maxi, heights[0] * (nse[i] - pse[i] - 1));
// // //     }
// // //     return maxi;
// // // }

// // // int main()
// // // {

// // //     return 0;
// // // }


// // #include<bits/stdc++.h>
// // using namespace std;
// // static const bool __boost = []()
// // {
// //     cin.tie(nullptr);
// //     cout.tie(nullptr);
// //     return ios_base::sync_with_stdio(false);
// // }();
// // int main()
// // {
// //     return 0;
// // }


// #include<bits/stdc++.h>
// using namespace std;
// static const bool __boost = []()
// {
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     return ios_base::sync_with_stdio(false);
// }();
// int main()
// {
//     vector<vector<int>(3),int>arr(3);
//     for(int i=0;i<)
//     return 0;
// }