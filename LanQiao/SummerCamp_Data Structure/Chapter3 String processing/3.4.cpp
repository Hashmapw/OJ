#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 10;
int son[N][26], cnt[N], idx; // 下标为0的点，既是根节点，又是空节点
char str[N];
vector<string> all;

void insert(char str[])
{
    int p = 0;
    for (int i = 0; str[i]; i++) // str结尾'\0'作为结束条件
    {
        cnt[p]++;
        int u = str[i] - 'a';
        if (!son[p][u])
            son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}

int query(string str)
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u])
            return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", str);
        all.push_back(str);
        insert(str);
    }
    for (auto &t : all)
    {
        int maxlen = 0;
        for (int i = 0; i <= t.length(); i++)
        {
            string temp = t.substr(0, i);
            if (query(temp) > 1)
                maxlen = max(maxlen, i);
        }
        cout << maxlen << endl;
    }
}