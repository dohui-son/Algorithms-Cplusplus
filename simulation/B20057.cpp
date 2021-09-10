#include <bits/stdc++.h>
using namespace std;

int n, x, y;
int64_t ans;
int g[501][501];
int dy[] = {0, 1, 0, -1};
int dx[] = {-1, 0, 1, 0};
int spread[] = {1, 1, 2, 2, 5, 7, 7, 10, 10, 55};
int y_0[] = {-1, 1, -2, 2, 0, -1, 1, -1, 1, 0};
int x_0[] = {1, 1, 0, 0, -2, 0, 0, -1, -1, -1};
int y_1[] = {-1, -1, 0, 0, 2, 0, 0, 1, 1, 1}; //ㅇㅕ기서부 체해기
int x_1[] = {-1, 1, -2, 2, 0, -1, 1, -1, 1, 0};
int y_2[] = {-1, 1, -2, 2, 0, -1, 1, -1, 1, 0};
int x_2[] = {-1, -1, 0, 0, 2, 0, 0, 1, 1, 1};
int y_3[] = {1, 1, 0, 0, -2, 0, 0, -1, -1, -1};
int x_3[] = {-1, 1, -2, 2, 0, -1, 1, -1, 1, 0};

void go(int dir, int kan)
{
    int yy = 0, xx = 0;
    while (kan--)
    {
        y = dy[dir] + y;
        x = dx[dir] + x;

        int a = g[y][x];
        for (int i = 0; i < 10; i++)
        {
            if (dir == 0)
            {
                yy = y_0[i];
                xx = x_0[i];
            }
            if (dir == 1)
            {
                yy = y_1[i];
                xx = x_1[i];
            }
            if (dir == 2)
            {
                yy = y_2[i];
                xx = x_2[i];
            }
            if (dir == 3)
            {
                yy = y_3[i];
                xx = x_3[i];
            }
            int ny = y + yy;
            int nx = x + xx;
            if (ny < 0 || nx < 0 || ny >= n || nx >= n)
            {
                if (i == 9)
                {
                    ans += a;
                    break;
                }
                ans += (g[y][x] * spread[i] / 100);
            }
            else
            {
                if (i == 9)
                {
                    g[ny][nx] += a;
                    break;
                }

                g[ny][nx] += (g[y][x] * spread[i] / 100);
            }
            a -= (g[y][x] * spread[i] / 100);
        }
    }
    g[y][x] = 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
        }
    }
    x = n / 2;
    y = n / 2;
    int kan = 0;
    for (int i = 0; i < n * 2 - 1; i++)
    {
        if (i % 2 == 0)
            kan++;
        int dir = i % 4;
        go(dir, kan);
    }
    cout << ans << endl;

    return 0;
}
