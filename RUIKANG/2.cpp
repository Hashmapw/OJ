#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int n, m, l;
map<int, int> nt;
pii bask[1010];
bool work[1010];
int num[1010];
int sale[10010];
vector<pair<int, int>> output;

bool cmp(pii t1,pii t2){
    if(t1.second<t2.second){
        return true;
    }
    else if(t1.second==t2.second){
        if(t1.first<t2.first)  return true;
        else   return false;
    }
    else return false;
}
int main()
{
    int temp;
    cin >> n >> m >> l;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        nt[i] = temp;
    }
    for (int i = 1; i <= l; i++)
    {
        cin >> sale[i];
    }
    memset(bask, 0, sizeof(bask));
    int nowtime = 0;

    for (int i = 1; i <= l; i++)
    {
        bool flag = false;
        for (int j = 1; j <= m; j++)
        { // 找到能加入的篮子
            if (!work[j])
            {
                bask[j] = {i, nt[sale[i]]};
                //cout<<"Insert"<<i<<" "<<nt[sale[i]]<<endl;
                work[j] = true;
                flag = true;
                break;
            }
        }
        if (flag == true)
            continue;
        else
        {
            bool freebask = false;
            while (1)
            {
                nowtime++;
                for (int j = 1; j <= m; j++)
                {
                    if (work[j])
                    {
                        bask[j].second -= 1;
                        if (bask[j].second <= 0)
                        {
                            output.push_back({bask[j].first, nowtime});
                            work[j] = false;
                            num[j] += 1;
                        }
                    }
                }
                for (int j = 1; j <= m; j++)
                {
                    if (!work[j])
                    {
                        freebask = true;
                        break;
                    }
                }
                if (freebask)
                    break;
            }
            i--;
        }
    }
    while (1)
    {
        bool allfinish = true;
        nowtime++;
        for (int j = 1; j <= m; j++)
        {
            if (work[j])
            {
                bask[j].second -= 1;
                if (bask[j].second <= 0)
                {
                    output.push_back({bask[j].first, nowtime});
                    work[j] = false;
                    num[j] += 1;
                }
            }
        }
        for (int j = 1; j <= m; j++)
        {
            if (work[j])
            {
                allfinish = false;
                break;
            }
        }
        if (allfinish)
            break;
    }
    sort(output.begin(),output.end(),cmp);
    bool first=false;
    for (auto &it : output)
    {
        if(first==false)  first=true;
        else   cout<<" ";
        cout << it.first << ":" << it.second;
    }
    cout<<endl;
    bool first=false;
    for (int i = 1; i <= m; i++)
    {
        if(first==false)  first=true;
        else   cout<<" ";
        cout << num[i] << " ";
    }
}
