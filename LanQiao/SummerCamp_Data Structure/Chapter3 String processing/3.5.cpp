#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int son[N][27], cnt[N], idx; // 下标为0的点，既是根节点，又是空节点
char str[N];

void insert(char str[])
{
    int p = 0;
    for (int i = 0; str[i]; i++) // str结尾'\0'作为结束条件
    {
        int u = str[i] - 'a';
        if (son[p][u] == 0)
            son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}

int query(char str[])
{
    int p = 0, ans = 0;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        p = son[p][u];
        if (p == 0)
            return ans;
        ans += cnt[p];
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    while (n--)
    {
        scanf("%s", str);
        insert(str);
    }
    while (m--)
    {
        scanf("%s", str);
        cout << query(str) << endl;
    }
}