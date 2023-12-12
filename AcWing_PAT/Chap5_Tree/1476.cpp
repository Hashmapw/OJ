#include <bits/stdc++.h>
using namespace std;

const int N = 110;

int n, m;
int h[N], e[N], ne[N], idx;
int cnt[N], max_depth;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u, int depth)
{
    if (h[u] == -1) // 叶子节点
    {
        cnt[depth]++;
        max_depth = max(max_depth, depth);
        return;
    }

    for (int i = h[u]; ~i; i = ne[i])
    {
        dfs(e[i], depth + 1);
    }
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h); // 便于发现尾节点（叶子节点）
    for (int i = 0; i < m; i++)
    {
        int id, k;
        cin >> id >> k;
        while (k--)
        {
            int son;
            cin >> son;
            add(id, son);
        }
    }
    dfs(1, 0);

    cout << cnt[0];
    for (int i = 1; i <= max_depth; i++)
        cout << " " << cnt[i];
    cout << endl;
}