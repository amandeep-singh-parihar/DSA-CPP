// fibonacci
#include <bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();

// revision 2
// TC O(2^N)
int fib(int n)
{
    if (n < 0) return -1;
    if (n == 1) return 0;
    if (n == 2) return 1;

    int ans = fib(n - 1) + fib(n - 2);
    // cout<<ans<<" ";
    return ans;
}

int fibonacci(int n){
    if(n<=1) return n;

    return fibonacci(n-1)+fibonacci(n-2);
}

int main()
{
    int n;
    cin >> n;
    // int ans = fib(n);
    int ans = fibonacci(n);
    cout << ans;
    return 0;
}