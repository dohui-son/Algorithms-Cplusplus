#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;
int n, m, a[10][10], temp[10][10], ans = 987654321;
vector<pair<int, int> > v;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

vector<pair<int, int> > extendCCTV(int vdx, int dir)
{
    vector<pair<int, int> > ch;
    int y = v[vdx].first;
    int x = v[vdx].second;
    if (a[y][x] == 1)
    {
        while (1)
        {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if (ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] != 6)
            {
                if (a[ny][nx] == 0)
                {
                    ch.push_back({ny, nx});
                    a[ny][nx] = 8;
                }
                y = ny;
                x = nx;
            }
            else
                break;
        }
    }
    else if (a[y][x] == 2)
    {
        for (int i = 0; i <= 2; i += 2)
        {
            int yy = y;
            int xx = x;
            while (1)
            {
                int ny = yy + dy[(dir + i) % 4];
                int nx = xx + dx[(dir + i) % 4];
                if (ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] != 6)
                {
                    if (a[ny][nx] == 0)
                    {
                        ch.push_back({ny, nx});
                        a[ny][nx] = 8;
                    }
                    yy = ny;
                    xx = nx;
                }
                else
                    break;
            }
        }
    }
    else if (a[y][x] == 3)
    {
        for (int i = 0; i < 2; i++)
        {
            int yy = y;
            int xx = x;
            while (1)
            {
                int ny = yy + dy[(dir + i) % 4];
                int nx = xx + dx[(dir + i) % 4];
                if (ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] != 6)
                {
                    if (a[ny][nx] == 0)
                    {
                        ch.push_back({ny, nx});
                        a[ny][nx] = 8;
                    }
                    yy = ny;
                    xx = nx;
                }
                else
                    break;
            }
        }
    }
    else if (a[y][x] == 4)
    {
        for (int i = 0; i < 3; i++)
        {
            int yy = y;
            int xx = x;
            while (1)
            {
                int ny = yy + dy[(dir + i) % 4];
                int nx = xx + dx[(dir + i) % 4];
                if (ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] != 6)
                {
                    if (a[ny][nx] == 0)
                    {
                        ch.push_back({ny, nx});
                        a[ny][nx] = 8;
                    }
                    yy = ny;
                    xx = nx;
                }
                else
                    break;
            }
        }
    }
    else if (a[y][x] == 5)
    {
        for (int i = 0; i < 4; i++)
        {
            int yy = y;
            int xx = x;
            while (1)
            {
                int ny = yy + dy[(dir + i) % 4];
                int nx = xx + dx[(dir + i) % 4];
                if (ny >= 0 && ny < n && nx >= 0 && nx < m && a[ny][nx] != 6)
                {
                    if (a[ny][nx] == 0)
                    {
                        ch.push_back({ny, nx});
                        a[ny][nx] = 8;
                    }
                    yy = ny;
                    xx = nx;
                }
                else
                    break;
            }
        }
    }
    return ch;
}

void dfs(int here)
{
    if (here == v.size())
    {
        int ret = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == 0)
                    ret++;
            }
        }
        ans = min(ret, ans);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        vector<pair<int, int> > cc = extendCCTV(here, i);
        dfs(here + 1);
        for (auto c : cc)
            a[c.first][c.second] = 0;
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] != 6 && a[i][j] != 0)
                v.push_back({i, j});
        }
    }
    dfs(0);
    cout << ans << "\n";
    return 0;
}
