#include <bits/stdc++.h>
//#include "../print.hpp";

#define endl "\n";
using namespace std;

int N, M, ans;
int visited[104][104], g[104][104];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void bfs()
{
    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));
    visited[0][0] = 1;
    while (q.size())
    {
        pair<int, int> now = q.front();
        q.pop();
        if (now.first == N - 1 && now.second == M - 1)
            break;
        for (int i = 0; i < 4; i++)
        {
            int ny = now.first + dy[i];
            int nx = now.second + dx[i];
            if (ny < 0 || nx < 0 || ny >= N || nx >= M)
                continue;
            if (visited[ny][nx] == 0 && g[ny][nx] == 1)
            {
                g[ny][nx] += g[now.first][now.second];
                visited[ny][nx] = 1;
                q.push(make_pair(ny, nx));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%1d", &g[i][j]);
        }
    }
    bfs();
    printf("%d", g[N - 1][M - 1]);

    //cout << g;

    return 0;
}
