#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e6 + 10;
ll l;
char p[N];
ll ne[N];


int main()
{
    cin >> l;
    cin >> p + 1;
    for (int i = 2, j = 0; i <= l; i++)
    {
        while (j && p[i] != p[j + 1])
            j = ne[j];
        if (p[i] == p[j + 1])
            j++;
        ne[i] = j;
    }
    cout<<l-ne[l];
}