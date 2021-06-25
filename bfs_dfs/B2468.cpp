#include <bits/stdc++.h>
#define endl "\n";
using namespace std;

//땅이 하나도 안 잠겼을때가 안전지대 최고 일수도 있다.

int N, ans, smallest = 101, biggest, ret;
int g[102][102];
vector<vector<int> > visited;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {-1, 0, 1, 0};

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> g[i][j];
            if (smallest > g[i][j])
                smallest = g[i][j];
            if (biggest < g[i][j])
                biggest = g[i][j];
        }
    }
    for (int k = smallest - 1; k < biggest; k++)
    {
        visited = vector<vector<int> >(N + 1, vector<int>(N + 1, 0));
        ret = 0;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (g[i][j] > k && visited[i][j] == 0)
                {
                    ret++;
                    queue<pair<int, int> > q;
                    q.push(make_pair(i, j));
                    visited[i][j] = 1;
                    while (!q.empty())
                    {
                        pair<int, int> now = q.front();
                        q.pop();
                        for (int jj = 0; jj < 4; jj++)
                        {
                            int ny = now.first + dy[jj];
                            int nx = now.second + dx[jj];
                            if (ny < 0 || nx < 0 || ny >= N || nx >= N)
                                continue;

                            if (g[ny][nx] > k && visited[ny][nx] == 0)
                            {
                                visited[ny][nx] = 1;
                                q.push(make_pair(ny, nx));
                            }
                        }
                    }
                }
            }
        }
        ans = max(ans, ret);
    }
    cout << ans << endl;

    return 0;
}