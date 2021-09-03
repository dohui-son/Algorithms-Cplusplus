#include <bits/stdc++.h>
using namespace std;

int n, m, ans1, ans2, ans3, visited[51][51], g[51][51], memo[2504];
const int dy[] = {0, -1, 0, 1};
const int dx[] = {-1, 0, 1, 0};

int dfs(int y, int x, int cnt)
{
    if (visited[y][x])
        return 0;
    int ret = 1;
    visited[y][x] = cnt;
    for (int i = 0; i < 4; i++)
    {
        if (!(g[y][x] & 1 << i))
        {
            int ny = dy[i] + y;
            int nx = dx[i] + x;

            ret += dfs(ny, nx, cnt);
        }
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> g[i][j];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited[i][j] == 0)
            {
                ans1++;
                memo[ans1] = dfs(i, j, ans1);
                ans2 = max(ans2, memo[ans1]);
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + 1 < m)
            {
                int a = visited[i + 1][j];
                int b = visited[i][j];
                if (a != b)
                    ans3 = max(ans3, memo[a] + memo[b]);
            }
            if (j + 1 < n)
            {
                int a = visited[i][j + 1];
                int b = visited[i][j];
                if (a != b)
                    ans3 = max(ans3, memo[a] + memo[b]);
            }
        }
    }
    cout << ans1 << "\n"
         << ans2 << "\n"
         << ans3 << "\n";

    return 0;
}