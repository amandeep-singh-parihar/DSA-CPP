// 2358. Maximum Number of Groups Entering a Competition

/*
You are given a positive integer array grades which represents the grades of students in a university. You would like to enter all these students into a competition in ordered non-empty groups, such that the ordering meets the following conditions:

The sum of the grades of students in the ith group is less than the sum of the grades of students in the (i + 1)th group, for all groups (except the last).
The total number of students in the ith group is less than the total number of students in the (i + 1)th group, for all groups (except the last).
Return the maximum number of groups that can be formed.



Example 1:

Input: grades = [10,6,12,7,3,5]
Output: 3
Explanation: The following is a possible way to form 3 groups of students:
- 1st group has the students with grades = [12]. Sum of grades: 12. Student count: 1
- 2nd group has the students with grades = [6,7]. Sum of grades: 6 + 7 = 13. Student count: 2
- 3rd group has the students with grades = [10,3,5]. Sum of grades: 10 + 3 + 5 = 18. Student count: 3
It can be shown that it is not possible to form more than 3 groups.
*/

#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// Intuition .
// First it doesn't matter how we make the group it just have to follow the condition
// it means for the example 1 if you make the gropu like [3],[5,6],[7,10,12]
// the ans still be 3 and satisfy all the condition.

// Approach 1
// now according to the question group be like current group has the size of +1 then its prev group
// and sume of element of all the group must be n (arr.size());
// we can use quadratic formula here like
// (i) + (i+1) + (i+2) + (i+3) + .... + (i+n-1) = arr.size();
// (n*i) + n*(n-1)/2 = size
// 2*n*i + n^2 = 2*size
// n^2 + n*i - 2*size = 0;
// lets calculate of i = 1; (1 student in the 0th group)
// formaula = ax^2 + bx + c;
// (-b ± √(b^2)-4*a*c)/2 , I take + for maximum
// (-1 + √1+8size)/2

int maximumGroups(vector<int> &grades)
{
    int res = (-1 + sqrt(1 + 8 * grades.size())) / 2;
    return res;
}

// Approach 2
// simple solution You just have to count the number in the ap
int _maximumGroups(vector<int> &grades)
{
    int n = grades.size();

    int x = 1;
    while (x * (x + 1) / 2 <= n)
    {
        ++x;
    }
    return --x;
}

int main()
{
    vector<int> grades = {10, 6, 12, 7, 3, 5};
    cout << maximumGroups(grades);
    return 0;
}