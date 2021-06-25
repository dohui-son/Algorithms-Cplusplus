#include <bits/stdc++.h>
using namespace std;

int N, M, ny, nx;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int visited[1004][1004], g[1004][1004];

void dfs(int y, int x)
{
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        ny = y + dy[i];
        nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= M)
            continue;
        if (g[ny][nx] == 1 && !visited[ny][nx])
            dfs(ny, nx);
    }
}

int main()
{
    return 0;
}