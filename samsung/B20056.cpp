#include <bits/stdc++.h>
using namespace std;
int n, m, k, rr, cc, mm, ss, dd;

const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};

struct F
{
    int y, x, mass, speed, dir;
};
vector<F> g[54][54];
vector<F> fire;

int next(int now, int kan)
{
    int ret = now + (kan % n);
    if (ret < 0)
        return ret + n;
    if (ret >= n)
        return ret - n;
    return ret;
}

void movemove()
{
    for (int idx = 0; idx < fire.size(); idx++)
    {
        F &now = fire[idx];
        int ny = next(now.y, dy[now.dir] * now.speed);
        int nx = next(now.x, dx[now.dir] * now.speed);
        now.y = ny;
        now.x = nx;
        g[ny][nx].push_back(now);
    }
    fire.clear();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (g[i][j].size() == 1)
                fire.push_back(g[i][j][0]);
            else if (g[i][j].size() >= 2)
            {
                mm = 0;
                ss = 0;
                bool even = true, odd = true;
                for (F ff : g[i][j])
                {
                    mm += ff.mass;
                    ss += ff.speed;
                    if (ff.dir % 2 == 0)
                        odd = false;
                    else
                        even = false;
                }
                mm = mm / 5;
                ss = (ss / g[i][j].size());
                if (mm == 0)
                {
                    g[i][j].clear();
                    continue;
                }
                if (even || odd) //모두 홀수이거나 짝수

                    for (int jj = 0; jj < 7; jj += 2)
                        fire.push_back({i, j, mm, ss, jj});

                else

                    for (int jj = 1; jj < 8; jj += 2)
                        fire.push_back({i, j, mm, ss, jj});
            }
            g[i][j].clear();
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        cin >> rr >> cc >> mm >> ss >> dd;
        rr--, cc--;
        fire.push_back({rr, cc, mm, ss, dd});
    }
    while (k--)
        movemove();
    int64_t ans = 0;
    for (int i = 0; i < fire.size(); i++)
        ans += fire[i].mass;
    cout << ans << "\n";
    return 0;
}