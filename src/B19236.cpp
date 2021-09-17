#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, 0, -1};
const int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
int ans, shy, shx, shd;

vector<vector<int> > gg(5, vector<int>(5, 0));
//bool live[17] = {1,};

vector<int> ffdir(19, 0);
vector<pair<int, int> > ffyx(19);

bool fishmove(vector<vector<int> > &g, vector<int> &fdir, vector<pair<int, int> > &fyx)
{
    bool ret = 0;
    for (int j = 1; j < 17; j++)
    {
        if (fdir[j] == -1)
            continue;
        ret = 1;
        int x = fyx[j].first;
        int y = fyx[j].second;
        int d = fdir[j];
        for (int i = 0; i < 8; i++)
        {
            int nd = (d + i) % 8;
            int ny = y + dy[nd];
            int nx = x + dx[nd];
            if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4)
                continue;
            if (shy == ny && shx == nx)
                continue;
            if (g[ny][nx] > 0)
            {
                g[y][x] = g[ny][nx];
                fyx[g[y][x]].first = y;
                fyx[g[y][x]].second = x;
            }
            g[ny][nx] = j;
            fyx[j].first = ny;
            fyx[j].second = nx;
            fdir[j] = nd;
            break;
        }
    }
    return ret;
}

void BT(int cnt, vector<vector<int> > g, vector<int> fdir, vector<pair<int, int> > fyx)
{
    bool eaten = 0;
    if (!fishmove(g, fdir, fyx))
    {
        ans = max(ans, cnt);
        return;
    }
    for (int i = 1; i < 4; i++)
    {
        int ny = shy + dy[shd] * i;
        int nx = shx + dx[shd] * i;
        if (ny >= 0 && nx >= 0 && ny < 4 && nx < 4 && g[ny][nx] > 0)
        {
            eaten = true;
            int tmpy = shy, tmpx = shx, tmpd = shd, ffnum = g[ny][nx], ffd = fdir[ffnum];
            shy = ny;
            shx = nx;
            shd = ffd;
            fdir[ffnum] = -1;
            g[ny][nx] = 0;
            BT(cnt + ffnum, g, fdir, fyx);
            shy = tmpy;
            shx = tmpx;
            shd = tmpd;
            g[ny][nx] = ffnum;
            fdir[ffnum] = ffd;
        }
    }
    if (!eaten)
    {
        ans = max(ans, cnt);
        return;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int num = 0, dir = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int num = 0, dir = 0;
            cin >> num >> dir;
            ffyx[num].first = i;
            ffyx[num].second = j;
            ffdir[num] = dir;
            gg[i][j] = num;
        }
    }
    shd = ffdir[gg[0][0]];
    ffdir[gg[0][0]] = -1;
    ans += gg[0][0];
    gg[0][0] = 0;
    BT(ans, gg, ffdir, ffyx);

    cout << ans << "\n";

    return 0;
}
