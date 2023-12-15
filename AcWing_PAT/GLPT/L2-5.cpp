#include <bits/stdc++.h>
using namespace std;

const int N = 55;
set<int> num[N];
int n, m, k;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &k);
        int temp;
        while (k--)
        {
            scanf("%d", &temp);
            num[i + 1].insert(temp);
        }
    }
    scanf("%d", &m);
    while (m--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        set<int> inter;
        set_intersection(num[a].begin(), num[a].end(), num[b].begin(), num[b].end(), inserter(inter, inter.begin()));
        double ans = (double)inter.size() / (num[a].size() + num[b].size() - inter.size());
        printf("%.2lf\%%\n", ans * 100);
    }
}