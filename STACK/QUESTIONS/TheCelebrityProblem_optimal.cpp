// The Celebrity Problem optimal
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

//revision needed

int celebrity(vector<vector<int>> &mat)
{
    int n = mat.size();
    stack<int> st;
    // step 1 : push all elements in the stack
    for (int i = 0; i < n; ++i)
    {
        st.push(i);
    }

    // step 2 : run discard method, to get a mightBeCelebrity
    while (st.size() != 1)
    {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        if (mat[a][b])
        {
            st.push(b);
        }
        else
        {
            st.push(a);
        }
    }

    // step 3 : check that single person is celebrity or not
    int mightBeCelebrity = st.top();
    st.pop();

    // celebrity should not know anyone
    for (int i = 0; i < n; ++i)
    {
        if (mat[mightBeCelebrity][i] != 0)
        {
            return -1;
        }
    }

    // everyone should know celebrity
    for (int i = 0; i < n; ++i)
    {
        if (mat[i][mightBeCelebrity] != 1 && i != mightBeCelebrity)
        {
            return -1;
        }
    }

    // mightBeCelebrity is the celebrity
    return mightBeCelebrity;
}

int main()
{
    // Example matrix
    vector<vector<int>> mat = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}};

    // Call the celebrity function
    int result = celebrity(mat);

    // Output the result
    if (result == -1)
    {
        cout << "No celebrity found" << endl;
    }
    else
    {
        cout << "The celebrity is person " << result << endl;
    }

    return 0;
}
