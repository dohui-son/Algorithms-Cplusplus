#include <bits/stdc++.h>
#include <tuple>
using namespace std;
#define endl "\n"

int n, m, k, a, b, c;
int y[14][14], yy[14][14];
vector<int> g[14][14];
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
vector<tuple<int, int, int> > v;

void springsummer()
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int dead = 0;
            vector<int> tmp;
            if (g[i][j].size() == 0)
                continue;
            sort(g[i][j].begin(), g[i][j].end());
            for (int jj = 0; jj < g[i][j].size(); jj++)
            {
                if (y[i][j] >= g[i][j][jj])
                {
                    y[i][j] -= g[i][j][jj];

                    tmp.push_back(g[i][j][jj]++);
                }
                else
                {
                    dead += (g[i][j][jj] / 2);
                }
            }
            g[i][j].clear();
            g[i][j] = tmp;
            y[i][j] += dead;
        }
    }
}
void fall()
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (g[i][j].size() == 0)
                continue;
            for (int jj = 0; jj < g[i][j].size(); jj++)
            {
                if (g[i][j][jj] % 5 == 0)
                {
                    for (int dd = 0; dd < 8; dd++)
                    {
                        int ny = dy[dd] + i;
                        int nx = dx[dd] + j;
                        if (ny < 0 || nx < 0 || ny >= n || nx >= n)
                            continue;
                        g[ny][nx].push_back(1);
                    }
                }
            }
        }
    }
}
void winter()
{
    for (int i = 0; i < v.size(); i++)
    {
        tie(a, b, c) = v[i];
        y[a][b] += c;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        a--, b--;
        y[a][b] = 5;
        v.push_back({a, b, c});
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        a--, b--;
        g[a][b].push_back(c);
    }
    while (k--)
    {
        springsummer();
        fall();
        winter();
    }
    int64_t ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (g[i][j].size() > 0)
            {
                ans += g[i][j].size();
            }
        }
    }
    cout << ans << endl;

    return 0;
}