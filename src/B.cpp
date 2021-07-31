#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <map>

#define endl "\n";

using namespace std;
int n, m;
int a[31][31];
int b[31][31];
int visit[31][31];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x, int vaccin)
{
    visit[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        if (ny < 0 || nx < 0 || ny >= n || nx >= m)
            continue;
        if (!visit[ny][nx] && a[ny][nx] == a[y][x])
        {
            dfs(ny, nx, vaccin);
        }
    }
    a[y][x] = vaccin;
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> b[i][j];
        }
    }
    int flag = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visit[i][j] && a[i][j] != b[i][j] && flag)
            {
                dfs(i, j, b[i][j]);
                flag = 0;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] != b[i][j])
            {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;

    return 0;
}