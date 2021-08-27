#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int y, x, dir, n, k, g[14][14], ans; //0은 흰색, 1은 빨간색, 2는 파란색이다.
vector<int> m[14][14];
struct Point
{
    int y, x, dir;
};
vector<Point> mal;
const int dy[] = {0, 0, 0, -1, 1};
const int dx[] = {0, 1, -1, 0, 0};

int reverDir(int i)
{
    if (i == 1)
        return 2;
    if (i == 2)
        return 1;
    if (i == 3)
        return 4;
    if (i == 4)
        return 3;
}

void movemal(int y, int x, int d, int ii)
{
    int ny = y + dy[d];
    int nx = x + dx[d];
    if (ny < 0 || ny >= n || nx < 0 || nx >= n || g[ny][nx] == 2)
    {
        mal[ii].dir = reverDir(d);
        ny = y + dy[mal[ii].dir];
        nx = x + dx[mal[ii].dir];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n || g[ny][nx] == 2)
            return;
    }
    vector<int> &v = m[y][x];
    vector<int> &nv = m[ny][nx];
    auto pos = find(v.begin(), v.end(), ii);
    if (g[ny][nx] == 1)
        reverse(pos, v.end());

    for (auto i = pos; i != v.end(); i++)
    {
        mal[*i].y = ny;
        mal[*i].x = nx;
        m[ny][nx].push_back(*i);
    }
    v.erase(pos, v.end());
    return;
}

bool isOver()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (m[i][j].size() >= 4)
                return true;
        }
    }
    return false;
}

bool simul()
{
    for (int i = 0; i < k; i++)
    {
        y = mal[i].y;
        x = mal[i].x;
        dir = mal[i].dir;
        movemal(y, x, dir, i);
        if (isOver())
            return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
        }
    }
    for (int i = 0; i < k; i++)
    {
        cin >> y >> x >> dir;
        y--, x--;
        mal.push_back({y, x, dir});
        m[y][x].push_back(i);
    }

    while (ans <= 1000)
    {
        ans++;
        if (simul())
            break;
    }
    if (ans <= 1000)
        cout << ans << endl;
    else
        cout << -1 << endl;

    return 0;
}