#include <bits/stdc++.h>
using namespace std;

const int N = 15;

int n;
int l[N], r[N];
int q[N];
bool has_father[N];

void dfs_reverse(int u)
{
    if (u == -1)
        return;

    dfs_reverse(l[u]);
    dfs_reverse(r[u]);
    swap(l[u], r[u]);
}

void bfs(int root)
{
    int hh = 0, tt = 0;
    q[0] = root;
    while (hh <= tt)
    {
        int t = q[hh++];
        if (l[t] != -1)
            q[++tt] = l[t];
        if (r[t] != -1)
            q[++tt] = r[t];
    }

    cout << q[0];
    for (int i = 1; i < n; i++)
        cout << " " << q[i];
    cout << endl;
}

void dfs(int u, int &k)
{
    if (u == -1)
        return;
    dfs(l[u], k);   // 递归遍历左子树

    cout << u;
    if (++k != n)
        cout << " ";

    dfs(r[u], k);  // 递归遍历右子树
}

int main()
{
    cin >> n;

    memset(l, -1, sizeof l);
    memset(r, -1, sizeof r);
    for (int i = 0; i < n; i++)
    {
        char lc, rc;
        cin >> lc >> rc;
        if (lc != '-')
            lc = lc - '0', has_father[l[i]] = true;
        if (rc != '-')
            rc = rc - '0', has_father[r[i]] = true;
    }

    int root = 0;
    while (has_father[root])
        root++;

    dfs_reverse(root);
    bfs(root, k);

    int k = 0;
    dfs(root, k);
}