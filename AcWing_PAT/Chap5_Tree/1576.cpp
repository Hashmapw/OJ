#include <bits/stdc++.h>
using namespace std;

const int N = 40;
int n;
int l[N], r[N];

void dfs(int u, int root)
{
    if (!u)
        return;
    dfs(l[u], root);
    dfs(r[u], root);

    cout << u;
    if (u != root)
        cout << " ";
}

int main()
{
    cin >> n;

    int root;
    int last = 0, type;
    stack<int> stk;
    for (int i = 0; i < n * 2; i++)
    {
        string op;
        cin >> op;
        if (op == "Push")
        {
            int x;
            cin >> x;
            if (!last)
            {
                root = x;
            }
            else
            {
                if (type == 0)
                    l[last] = x;
                else
                    r[last] = x;
            }
            stk.push(x);
            last = x;
            type = 0; // 表示push
        }
        else
        {
            last = stk.top();
            stk.pop();
            type = 1; // 表示pop
        }
    }
    dfs(root, root);
}