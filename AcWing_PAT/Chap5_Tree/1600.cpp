#include <bits/stdc++.h>
using namespace std;

const int N = 25;

int n;
int l[N], r[N];
bool has_father[N];
int maxk, max_id;

void dfs(int u, int k)
{
    if (u == -1)
        return;
    if (k > maxk)
    {
        maxk = k;
        max_id = u;
    }
    dfs(l[u], k * 2);
    dfs(r[u], k * 2 + 1);
}

int main()
{
    memset(l, -1, sizeof l);
    memset(r, -1, sizeof r);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string a, b;
        cin >> a >> b;
        if (a != "-")
            l[i] = stoi(a), has_father[l[i]] = true;
        if (b != "-")
            r[i] = stoi(b), has_father[r[i]] = true;
    }

    int root = 0;
    while (has_father[root])
        root++;

    dfs(root, 1);

    if (maxk == n)
        printf("YES %d\n", max_id);
    else
        printf("NO %d\n", root);
}