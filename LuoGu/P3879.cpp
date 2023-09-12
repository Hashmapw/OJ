#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;
typedef pair<int, int> pii;
int n, m, k;
int son[N][26], cnt[N], idx; // 下标为0的点，既是根节点，又是空节点
char str[N];
set<int> loc[N];

void insert(char str[], int now)
{
    int p = 0;
    for (int i = 0; str[i]; i++) // str结尾'\0'作为结束条件
    {
        int u = str[i] - 'a';
        if (!son[p][u])
            son[p][u] = ++idx;
        p = son[p][u];
    }
    loc[p].insert(now);
    cnt[p]++;
}

void query(char str[])
{
    int p = 0;
    bool flag = true, first = false;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u])
            flag = false;
        p = son[p][u];
    }
    if (flag)
    {
        for (auto i : loc[p])
        {
            if (first == false)
                first = true;
            else
                cout << " ";
            cout << i;
        }
    }
    cout << endl;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> m;
        while (m--)
        {
            cin >> str;
            insert(str, i);
        }
    }
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> str;
        query(str);
    }
}