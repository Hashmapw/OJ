unordered_map<int, int> primes;

while (n--) // 需要求n个数乘积的约数个数
{
    int x;
    cin >> x;

    for (int i = 2; i <= x / i; i++)
    {
        while (x % i == 0)
        {
            x /= i;
            primes[i]++;
        }
    }

    if (x > 1)
        primes[x]++;
}

ll res = 1;
for (auto prime : primes)
{
    int p = prime.first, a = prime.second;
    ll t = 1;
    while (a--)
        t = (t * p + 1) % mod;
    res = res * t % mod;
}