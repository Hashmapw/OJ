#include <bits/stdc++.h>
using namespace std;

const int N = 100 + 10;

int r, c;
string answer;
char matrix[N][N];
bool already[N][N];
queue<pair<char, pair<int, int>>> q;
stack < pair<char, pair<int, int>> s;

void bfs(int x, int y)
{
    q.push({matrix[x][y], {x, y}});
    already[x][y] = true;

    int pos = 0;

    while (!q.empty())
    {
        char temp = q.front().first;
        int tempx = q.front().second.first, tempy = q.front().second.second;
        if (temp == answer[pos])
            pos++;
        q.pop();

        while (!q.empty())
        {
        }
    }
}

int main()
{
    getline(cin, answer);
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> matrix[i][j];
        }
    }
    bfs(0, 0);
}