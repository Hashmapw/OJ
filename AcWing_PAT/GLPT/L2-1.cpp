#include <bits/stdc++.h>
using namespace std;

const int N = 510;

int n, m, s, d;
vector<int> num;

typedef pair<int, int> PII;
int g[N][N];
int dist[N];                      // 存储所有点到1号点的距离
bool st[N];                       // 存储每个点的最短距离是否已确定

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void printPath(vector<int> &pre, int u)
{
    if (u == s)
    {
        cout << u << " ";
        return;
    }
    printPath(pre, pre[u]);
    cout << u << " ";
}

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[s] = 0;

    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
        {
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        }
        st[t] = true;

        for (int j = 1; j <= n; j++)
        {
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }
    if (dist[d] == 0x3f3f3f3f)
        return -1;
    return dist[d];
}

int main()
{
    cin >> n >> m >> s >> d;
    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        cin >> temp;
        num.push_back(temp);
    }
    int a, b, c;
    memset(g,0x3f,sizeof g);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }

    int ans = dijkstra();
    cout << "Shortest distance: " << ans << endl;

    if (ans != -1)
    {
        vector<int> pre(n + 1, -1);
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (dist[j] == dist[i] + g[i][j])
                {
                    pre[j] = i;
                }
            }
        }

        cout << "Shortest path: ";
        printPath(pre, d);
        cout << endl;
    }
}