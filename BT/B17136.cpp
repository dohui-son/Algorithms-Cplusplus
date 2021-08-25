#include <bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <algorithm>
using namespace std;
#define endl "\n"
const int INF = 26;
map<int, int> m;
int n = 10, g[10][10], ans = 26;

void paint(int y, int x, int sizee, int color)
{
    for (int i = y; i < y + sizee; i++)
    {
        for (int j = x; j < x + sizee; j++)
        {
            g[i][j] = color;
        }
    }
}

bool check(int y, int x, int sizee)
{
    if (y + sizee > n || x + sizee > n)
        return false;
    for (int i = y; i < y + sizee; i++)
    {
        for (int j = x; j < x + sizee; j++)
        {
            if (g[i][j] == 0)
                return false;
        }
    }
    return true;
}

void dfs(int y, int x, int cnt)
{
    if (cnt >= ans)
        return;
    if (y == n)
    {
        ans = min(ans, cnt);
        return;
    }
    if (x == n)
    {
        dfs(y + 1, 0, cnt);
        return;
    }
    if (g[y][x] == 0)
    {
        dfs(y, x + 1, cnt);
        return;
    }
    for (int sizee = 5; sizee >= 1; sizee--)
    {
        if (m[sizee] >= 5)
            continue;
        if (check(y, x, sizee))
        {
            m[sizee]++;
            paint(y, x, sizee, 0);
            dfs(y, x + sizee, cnt + 1);
            paint(y, x, sizee, 1);
            m[sizee]--;
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
        }
    }
    dfs(0, 0, 0);
    cout << (ans >= INF ? -1 : ans) << endl;

    return 0;
}