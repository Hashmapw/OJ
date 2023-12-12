#include <bits/stdc++.h>
using namespace std;

int n, maxn;
vector<int> query;
int primes[N], cnt; // primes[]存储所有素数
bool st[N];         // st[x]存储x是否被筛掉

void get_primes(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
            primes[cnt++] = i;
        for (int j = i + i; j <= n; j += i)
        {
            st[j] = true;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        cin >> temp;
        query.push_back(temp);
    }
    maxn = *max_element(query.front(), query.back());
    get_primes(maxn);
    for(auto x:query){
        
    }
}
