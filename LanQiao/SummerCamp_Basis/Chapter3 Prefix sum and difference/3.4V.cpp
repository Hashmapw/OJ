#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10;

ll n;
ll s[N];
map<int, int> m;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%1d", &s[i]);
    }
    int x = 0;
    ll sum = 0;
    m[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 1)
            x = x - 1;
        else if(s[i]==0)
            x = x + 1;
        sum += m[x];
        m[x]++;
    }
    cout << sum;
}
/*
318 
111101101001001001001111100011110011000111010110111100101011101101011010000011000001111010100110101110011001100101100010000011100101011110111010000011001111111001010010010100010110110001101101111001100001000111110111100100010001001010001111010100100110000101111111101001011000011100010010011111101000011101101111100011
*/