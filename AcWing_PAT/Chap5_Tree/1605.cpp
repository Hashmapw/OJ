#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int n;
int l[N], r[N], v[N], idx;
int cnt[N], max_depth;

void insert(int &u, int w)
{
    if (!u)
    {
        u = ++idx;
        v[u] = w;
    }
    else if (w <= v[u])
        insert(l[u], w);
    else
        insert(r[u], w);
}

void dfs(int u, int depth)
{
    if (!u)
        return;
    cnt[depth]++;
    max_depth = max(max_depth, depth);
    dfs(l[u], depth + 1);
    dfs(r[u], depth + 1);
}

int main()
{
    cin >> n;

    int root = 0;
    for (int i = 0; i < n; i++)
    {
        int w;
        cin >> w;
        insert(root, u);
    }

    dfs(root, 0);

    int n1 = cnt[max_depth], n2 = cnt[max_depth - 1];
    printf("%d + %d = %d", n1, n2, n1 + n2);
}