#include <bits/stdc++.h>

using namespace std;
#define endl "\n";
int T, M, N, K, x, y, ans;
vector<vector<int> > g, visited;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void dfs(int y, int x)
{
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= M)
            continue;
        if (!visited[ny][nx] && g[ny][nx] == 1)
            dfs(ny, nx);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> M >> N >> K;
        ans = 0;
        g = vector<vector<int> >(N, vector<int>(M, 0));
        visited = vector<vector<int> >(N, vector<int>(M, 0));
        for (int j = 0; j < K; j++)
        {
            cin >> x >> y;
            g[y][x] = 1;
        }
        for (int nn = 0; nn < N; nn++)
        {
            for (int mm = 0; mm < M; mm++)
            {
                if (!visited[nn][mm] && g[nn][mm] == 1)
                {
                    dfs(nn, mm);
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
