#include <iostream>
#include <vector>
#include <queue>

#define endl "\n";

using namespace std;
int T, M, N, K;
vector<vector<int>> field;
vector<vector<bool>> visit;

int yy[4] = {-1, 0, 1, 0};
int xx[4] = {0, 1, 0, -1};

int BFS()
{
    int ret = 0;
    queue<pair<int, int>> q;
    for (int x = 0; x < M; x++)
        for (int y = 0; y < N; y++)
        {
            if (field[x][y] && !visit[x][y])
            {

                q.push(make_pair(x, y));
                visit[x][y] = true;
                ret++;
                while (!q.empty())
                {
                    pair<int, int> now = q.front();
                    q.pop();
                    int nx = now.first;
                    int ny = now.second;
                    for (int i = 0; i < 4; i++)
                    {
                        int ty = ny + yy[i];
                        int tx = nx + xx[i];
                        if (ty < 0 || tx < 0 || tx >= M || ty >= N)
                            continue;
                        if (visit[tx][ty] || !field[tx][ty])
                            continue;
                        q.push(make_pair(tx, ty));
                        visit[tx][ty] = true;
                    }
                }
            }
        }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> T;
    int x, y;

    for (int i = 0; i < T; i++)
    {
        cin >> M >> N >> K;
        field = vector<vector<int>>(M, vector<int>(N, 0));
        visit = vector<vector<bool>>(M, vector<bool>(N, false));
        for (int j = 0; j < K; j++)
        {
            cin >> x >> y;

            field[x][y] = 1;
        }

        cout << BFS() << endl;
    }

    return 0;
}