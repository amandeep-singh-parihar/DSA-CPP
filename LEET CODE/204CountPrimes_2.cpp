#include <bits/stdc++.h>
using namespace std;
#define N 10005
int get_prime(int p[], int n)
{
    int len = 0;
    static int f[N];
    memset(f + 1, 0, sizeof(int) * n);
    for (int i = 2; i <= n; ++i)
    {
        if (!f[i])
            f[i] = p[++len] = i;
        for (int j = 1; j <= len && p[j] <= f[i] && i * p[j] <= n; ++j)
            f[i * p[j]] = p[j];
    }
    return len;
}

int p[N], v[N], S[N], v1, p1;

int countPrimes(int n)
{
    n = max(n - 1, 1);
    int r = floor(sqrt((double)n));
    if ((r + 1) * (r + 1) <= n)
        ++r;
    p1 = get_prime(p, r);
    v1 = 0;
    for (int i = 1; i <= r; ++i)
        v[v1++] = i;
    if (n / r > r)
        v[v1++] = n / r;
    for (int i = r - 1; i; --i)
        v[v1++] = n / i;
    for (int i = 0; i < v1; ++i)
        S[i] = v[i] - 1;
    for (int i = 1; i <= p1; ++i)
    {
        int t = p[i], j;
        int t1 = t * (r + 1), t2 = t * t;
        double invt = 1. / t;
        int k;
        for (j = v1 - 1; v[j] >= t2; --j)
        {
            k = v[j] * invt + 1e-9; // v[j]/t
            S[j] -= (S[v[j] < t1 ? k - 1 : v1 - n / k] - S[t - 2]);
        }
    }
    return S[v1 - 1];
}

int main()
{
    int n;
    cin >> n;
    cout << countPrimes(n);
    return 0;
    return 0;
}