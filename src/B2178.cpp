//BFS사용하는 경우: 두 노드 사이의 최단 경로 혹은 임의의 경로를 찾고 싶을 때 이 방법을 선택한다

#include <iostream>
#include <vector>
#include <queue>

#define endl "\n";

using namespace std;
int N, M;
vector<vector<int>> maze;

int xx[4] = {0, 1, 0, -1};
int yy[4] = {-1, 0, 1, 0};

void BFS()
{
    queue<pair<int, int>> q;
    int count = 0;
    q.push(make_pair(0, 0));

    while (!q.empty())
    {
        pair<int, int> now = q.front();
        q.pop();

        int y = now.first;
        int x = now.second;

        for (int i = 0; i < 4; i++)
        {
            int next_y = y + yy[i];
            int next_x = x + xx[i];
            if (next_y >= 0 && next_x >= 0 && next_y < N && next_x < M && maze[next_y][next_x] == 1)
            {
                q.push(make_pair(next_y, next_x));
                maze[next_y][next_x] = maze[y][x] + 1;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    char num;
    cin >> N >> M;
    maze = vector<vector<int>>(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++)

        for (int j = 0; j < M; j++)
        {
            cin >> num;
            if (num == '1')
                maze[i][j] = 1;
        }

    BFS();

    cout << maze[N - 1][M - 1];

    return 0;
}