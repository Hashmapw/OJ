#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10;

typedef long long ll;
ll n, q;
ll l, r;
ll pre[N];
vector<int> prime;
bool primeStatus[N] = {true, true}; // 0和1均不是素数

void fastPrime(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (primeStatus[i] == false)
        {
            prime.push_back(i);
        }
        for (ll j = 0; j < prime.size() && i * prime[j] <= n; j++)
        {
            primeStatus[i * prime[j]] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}

int main()
{
    scanf("%ld %ld", &n, &q);
    fastPrime(n);
    for (int i = 1; i <= n; i++)
    {
        if (primeStatus[i / 2] == false && primeStatus[i] == false)
        {
            pre[i] = pre[i - 1] + 1;
        }
        else
        {
            pre[i] = pre[i - 1];
        }
    }
    while (q--)
    {
        ll l, r;
        scanf("%ld %ld", &l, &r);
        printf("%ld\n", pre[r] - pre[l - 1]);
    }
}