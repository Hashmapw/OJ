#include <bits/stdc++.h>
#define INF 1e6
using namespace std;

const int N = 1e5 + 10;
typedef pair<int, int> PII;
typedef pair<int, PII> LINK;
LINK all[N];
unordered_set<int> num;
unordered_map<int, int> has;
vector<LINK> ans;
vector<PII> del;
int start, n;

int main()
{
    cin >> start >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (c == -1)
            c = INF;
        all[i].first = b;
        all[i].second.first = a;
        all[i].second.second = c;
        has[a] = i;
    }
    int i = has[start], pos;
    bool re = false;
    while (1)
    {
        if (num.find(abs(all[i].first)) == num.end())
        {
            num.insert(abs(all[i].first));
            ans.push_back(all[i]);
        }
        else
        {
            int temp = all[i].second.first;

            num.insert(abs(all[i].first));
            while (num.find(abs(all[i].first)) != num.end())
            {
                if (all[i].second.second == INF)
                {
                    re = true;
                    del.push_back({all[i].first, all[i].second.first});    // 存在冲突且非第一次插入，需要特殊处理
                    break;
                }
                del.push_back({all[i].first, all[i].second.first});
                pos = i;
                i = has[all[i].second.second];
            }
            for (auto &v : ans)
            {
                if (v.second.second == temp)
                {
                    v.second.second = all[i].second.first;
                }
            }
            i = pos;
        }
        if (all[pos].second.second == INF || re)
        {
            break;
        }
    }

    int size = ans.size();
    for (int i = 0; i < size - 1; i++)
    {
        if (ans[i].second.second == INF)
            ans[i].second.second = -1;
        printf("%05d %d %05d\n", ans[i].second.first, ans[i].first, ans[i].second.second);
    }
    printf("%05d %d -1\n", ans[size - 1].second.first, ans[size - 1].first);

    size = del.size();
    if (size == 0)
        return 0;
    for (int i = 0; i < size - 1; i++)
    {
        printf("%05d %d %05d\n", del[i].second, del[i].first, del[i + 1].second);
    }
    printf("%05d %d -1", del[size - 1].second, del[size - 1].first);
}
