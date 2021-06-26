#include <bits/stdc++.h>
#define endl "\n";

using namespace std;
int M, N, K, x1, y1, x2, y2, ww;
int visited[102][102], g[102][102];
vector<int> w;
vector<vector<int> > input;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    cin >> M >> N >> K;
    input = vector<vector<int> >(K, vector<int>(4, 0));

    for (int i = 0; i < K; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int xx = a; xx < c; xx++)
        {
            for (int yy = b; yy < d; yy++)
            {
                visited[yy][xx] = -1;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (visited[i][j] == 0)
            {
                queue<pair<int, int> > q;
                q.push(make_pair(i, j));
                visited[i][j] = 1;
                ww = 0;
                while (!q.empty())
                {
                    pair<int, int> now = q.front();
                    q.pop();

                    ww = max(ww, visited[now.first][now.second]);
                    for (int d = 0; d < 4; d++)
                    {
                        int ny = dy[d] + now.first;
                        int nx = dx[d] + now.second;
                        if (ny < 0 || nx < 0 || ny >= M || nx >= N)
                            continue;
                        if (visited[ny][nx] == 0)
                        {
                            q.push(make_pair(ny, nx));
                            visited[ny][nx] = visited[now.first][now.second] + 1;
                        }
                    }
                }
                w.push_back(ww);
            }
        }
    }
    sort(w.begin(), w.end());
    cout << w.size() << endl;
    for (int i = 0; i < w.size(); i++)
    {
        cout << w[i] << " ";
    }

    return 0;
}