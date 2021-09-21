#include <bits/stdc++.h>
#define fori for (int i = 1; i <= 20; i++)
#define forj for (int j = 1; j <= 20; j++)

using namespace std;
using pi = pair<int, int>;
using ti = tuple<pi, int, int>;

const int xx[] = {1, -1, 0, 0};
const int yy[] = {0, 0, 1, -1};

int v[22][22];

void rt()
{
    int w[22][22];
    fori forj w[i][j] = v[j][21 - i];
    fori forj v[i][j] = w[i][j];
}

void grv()
{
    fori for (int j = 21; j > 0; j--) if (v[j][i] == -1)
    {
        int lst = j - 1;
        for (int k = j - 1; k > 0; k--)
        {
            if (v[k][i] == -1)
            {
                j = k + 1;
                break;
            }
            if (v[k][i] >= 0)
                swap(v[k][i], v[lst][i]), lst--;
        }
    }
}

pi operator+(pi p1, pi p2)
{
    return pi(p1.first + p2.first, p1.second + p2.second);
}

int vis[22][22];
pi dfs(int x, int y, int z, bool b = false)
{
    if (b)
        v[x][y] = -2;
    vis[x][y] = 1;
    pi r(1, v[x][y] == 0 ? 1 : 0);
    for (int i = 0; i < 4; i++)
    {
        int x_ = x + xx[i], y_ = y + yy[i];
        if (!vis[x_][y_] && (v[x_][y_] == 0 || v[x_][y_] == z))
            r = r + dfs(x_, y_, z, b);
    }
    return r;
}

void clear()
{
    fori forj if (v[i][j] == 0) vis[i][j] = 0;
}

int get()
{
    ti r(pi(0, 0), 1, 1);
    memset(vis, 0, sizeof(vis));
    fori forj if (v[i][j] > 0) clear(), r = max(r, ti(dfs(i, j, v[i][j]), i, j));
    memset(vis, 0, sizeof(vis));
    auto [d, x, y] = r;
    if (d.first)
        dfs(x, y, v[x][y], true);
    return d.first;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    memset(v, -1, sizeof(v));

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> v[i][j];

    int a = 0;
    while (1)
    {
        int d = get();
        if (d < 2)
            break;
        a += d * d;
        grv();
        rt();
        grv();
    }
    cout << a << '\n';

    return 0;
}