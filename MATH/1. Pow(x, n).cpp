// 50. Pow(x, n)
#include<bits/stdc++.h>
using namespace std;
static const bool __boost = []()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
#define ll long long

double findPower(double a,int b){
    if(b==0) return 1;

    double half = findPower(a,b/2);
    double result = half * half;
    if(b%2==1){
        result = result * a;
    }
    return result;
}

double myPow(double x, int n){
    ll N = n;
    if(N<0){
        x = 1/x;
        N = -N;
    }
    return findPower(x,N);
}

int main()
{
    
    double x = 2.00000;
    int n = 10;
    cout<<myPow(x,n);
    return 0;
}