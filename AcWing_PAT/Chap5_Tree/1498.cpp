#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, M = 2e5 + 10;

int n;
int h[N], e[M], ne[M], idx;
int p[N];

int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int dfs(int u, int father)
{
    int depth = 0;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j == father)
            continue;
        depth = max(depth, dfs(j, u) + 1);
    }
    return depth;
}

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int main()
{
    cin >> n;

    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i++)
        p[i] = i;

    int k = n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        if (find(a) != find(b))
        {
            k--;
            p[find(a)] = find(b);
        }
        add(a, b), add(b, a);
    }
    if (k != 1)
    {
        printf("Error: %d components", k);
    }
    else
    {
        vector<int> nodes;
        int max_depth = -1;

        for (int i = 1; i <= n; i++)
        {
            int depth = dfs(i, -1);
            if (depth > max_depth)
            {
                max_depth = depth;
                nodes.clear();
                nodes.push_back(i);
            }
            else if (depth == max_depth)
                nodes.push_back(i);
        }
        for (auto v : nodes)
            cout << v << endl;
    }
}