#include <bits/stdc++.h>
using namespace std;

int n, q, l[1001], now_x, now_y, ans1, ans2, ret;
int g[1 << 6][1 << 6];
bool vis[1 << 6][1 << 6];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
void dfs(int sy, int sx)
{
    ret++;
    for (int i = 0; i < 4; i++)
    {
        int ny = sy + dy[i];
        int nx = sx + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= n || g[ny][nx] == 0 || vis[ny][nx])
            continue;
        vis[ny][nx] = 1;

        dfs(ny, nx);
    }
}

void melt()
{
    vector<pair<int, int> > tmp;
    ans1 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (g[i][j] == 0)
                continue;
            int cnt = 0;
            for (int dir = 0; dir < 4; dir++)
            {
                int ny = dy[dir] + i;
                int nx = dx[dir] + j;
                if (ny < 0 || nx < 0 || ny >= n || nx >= n || g[ny][nx] == 0)
                    continue;
                cnt++;
                if (cnt == 3)
                    break;
            }
            if (cnt < 3)
            {
                tmp.push_back({i, j});
            }

            ans1 += g[i][j];
        }
    }
    for (int i = 0; i < tmp.size(); i++)
    {
        g[tmp[i].first][tmp[i].second]--;
    }

    ans1 -= tmp.size();
}

void rotation(int size_)
{
    int tmp[size_ + 1][size_ + 1], cnt = 0;
    for (int i = now_y; i < now_y + size_; i++)
    {
        //gg를 gear[gdx][0]에서 gear[gdx][7]까지 복사해주기 --#include <algorithm>
        //copy(&gg[0], &gg[0] + 8, &gear[gdx][0]);
        // 복사할 대상 시작주소,복사할대상 시작주소+데이터수, 복사되어야할 공간의 첫 주소
        copy(&g[i][now_x], &g[i][now_x] + size_ + 1, &tmp[cnt][0]);
        // for (int j = 0; j < size_; j++)
        // {
        //     cout << tmp[cnt][j] << " ";
        // }
        // cout << endl;

        cnt++;
    }
    int x = now_x + size_ - 1;
    for (int i = 0; i < size_; i++)
    {

        for (int j = 0; j < size_; j++) //y == j
        {
            g[j + now_y][x] = tmp[i][j];
        }
        x--;
    }
}

void find_start(int size_)
{
    if (now_x + size_ >= n)
    {
        now_x = 0;
        now_y += size_;
        return;
    }
    now_x += size_;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> q;
    n = (1 << n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
        }
    }
    for (int i = 0; i < q; i++)
    {
        cin >> l[i];
    }
    int cnt = 0, tmp = 0;
    for (int i = 0; i < q; i++)
    {
        tmp = (1 << l[i]);
        cnt = (n * n) / (tmp * tmp);
        while (cnt--)
        {
            rotation(tmp);
            find_start(tmp);
        }

        now_x = 0;
        now_y = 0;
        melt();
        // cout << endl;
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cout << g[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!vis[i][j] && g[i][j] > 0)
            {
                vis[i][j] = 1;
                dfs(i, j);
                ans2 = max(ret, ans2);
                ret = 0;
            }
        }
    }

    cout << ans1 << "\n"
         << ans2 << "\n";

    return 0;
}
