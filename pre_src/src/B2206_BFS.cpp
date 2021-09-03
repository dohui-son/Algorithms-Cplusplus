//조금 어려웠음
#include <iostream>
#include <queue>
using namespace std;
#define endl "\n";

struct Path_data
{
    int x, y, bomb;
};
int N, M, dis = 1, ans = 0;
char map[1001][1001]; //입력 주의
bool isVisited[1001][1001][2];
int xx[4] = {1, -1, 0, 0};
int yy[4] = {0, 0, 1, -1};

queue<Path_data> q;

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> map[i];

    Path_data s;
    s.x = 0, s.y = 0, s.bomb = 0;
    q.push(s);
    isVisited[s.x][s.y][s.bomb] = true;

    while (!q.empty())
    {
        int q_size = q.size();
        while (q_size--)
        {
            Path_data now = q.front();
            q.pop();
            int x = now.x, y = now.y, b = now.bomb;

            if (x == N - 1 && y == M - 1)
            {
                ans = dis;
                cout << ans << endl;
                return 0;
            }
            for (int i = 0; i < 4; i++)
            {
                if (x + xx[i] >= 0 && x + xx[i] < N && y + yy[i] >= 0 && y + yy[i] < M && !isVisited[x + xx[i]][y + yy[i]][b] && map[x + xx[i]][y + yy[i]] == '0')
                {
                    //방문 안했고, 벽으로 막히지 않았음

                    isVisited[x + xx[i]][y + yy[i]][b] = true; //방문했다는 사실 기록
                    Path_data next;
                    next.x = x + xx[i], next.y = y + yy[i], next.bomb = b;
                    q.push(next);
                }
            }
            if (b == 0)
            { //아직 벽 한번도 안 부순 상태
                for (int i = 0; i < 4; i++)
                {
                    if (x + xx[i] >= 0 && x + xx[i] < N && y + yy[i] >= 0 && y + yy[i] < M && !isVisited[x + xx[i]][y + yy[i]][b])
                    {

                        isVisited[x + xx[i]][y + yy[i]][b + 1] = true;
                        Path_data next;
                        next.x = x + xx[i], next.y = y + yy[i], next.bomb = b + 1;
                        q.push(next);
                    }
                }
            }
        }
        dis++;
    }
    if (ans == 0)
        cout << -1 << endl;
    return 0;
}