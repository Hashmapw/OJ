#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int n;
int w[N], tr[N];

void dfs(int u, int &k) // 中序遍历
{
    if (u * 2 <= n)
        dfs(u * 2, k);
    tr[u] = w[k++];
    if (u * 2 + 1 <= n)
        dfs(u * 2 + 1, k);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> w[i];

    sort(w, w + n);

    int k = 0;
    dfs(1, k);

    cout << tr[1];
    for (int i = 2; i <= n; i++)
        cout << " " << tr[i];
}