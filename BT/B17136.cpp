#include <bits/stdc++.h>

using namespace std;
#define endl "\n"

const int INF = 26;
int a[104][104], ret = INF, n = 10;
map<int, int> mp;

void draw(int y, int x, int cnt, int value)
{
    for (int i = y; i < y + cnt; i++)
    {
        for (int j = x; j < x + cnt; j++)
        {
            a[i][j] = value;
        }
    }
}

bool check(int y, int x, int cnt)
{
    if (y + cnt > n || x + cnt > n)
        return false;
    for (int i = y; i < y + cnt; i++)
    {
        for (int j = x; j < x + cnt; j++)
        {
            if (a[i][j] == 0)
                return false;
        }
    }
    return true;
}

void dfs(int y, int x, int cnt)
{
    if (cnt >= INF)
        return;
    if (x == n)
    {
        dfs(y + 1, 0, cnt);
        return;
    }
    if (y == n)
    {
        ret = min(cnt, ret);
        return;
    }
    if (a[y][x] == 0)
    {
        dfs(y, x + 1, cnt);
        return;
    }

    for (int _size = 5; _size >= 1; _size--)
    {
        if (mp[_size] == 5)
            continue;
        if (check(y, x, _size))
        {
            mp[_size]++;
            draw(y, x, _size, 0);
            dfs(y, x + _size, 0);
            draw(y, x, _size, 1);
            mp[_size]--;
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
            cin >> a[i][j];
        }
    }
    dfs(0, 0, 0);
    cout << (ret == INF ? -1 : ret) << endl;
    return 0;
}