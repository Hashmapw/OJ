#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, pair<ll, ll>> ppll;
const int N = 1e6 + 10;

ll n;
string s;
ll ability[N];
priority_queue<ppll, vector<ppll>, greater<ppll>> q;
queue<ppll> ans;
bool already[N];


int main()
{
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++)
        cin >> ability[i];
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i + 1] != s[i])
            q.push({abs(ability[i + 1] - ability[i]), {i, i + 1}});
    }
    while (q.size() != 0)
    {
        ll x = q.top().second.first, y = q.top().second.second;
        if (already[x] == false && already[y] == false)
        {
            ans.push(q.top());
            already[x] = true;
            already[y] = true;
            q.pop();
            x = x - 1, y = y + 1;
            while (x >= 0 && already[x] == true)
                x--;
            while (y < n && already[y] == true)
                y++;
            if (x >= 0 && y < n && s[x] != s[y])
                q.push({abs(ability[x] - ability[y]), {x, y}});
        }
        else if (already[x] == true || already[y] == true)
        {
            q.pop();
        }
    }
    cout << ans.size() << endl;
    while (ans.size() != 0)
    {
        cout << ans.front().second.first + 1 << " " << ans.front().second.second + 1 << endl;
        ans.pop();
    }
}