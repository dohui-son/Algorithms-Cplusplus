#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define endl "\n";

using namespace std;
vector<vector<int>> tomato;
queue<pair<int, int>> q;
int row, col;
int xx[4] = {0, 1, 0, -1};
int yy[4] = {1, 0, -1, 0};

int BFS()
{
    int max_date = 1;
    while (!q.empty())
    {
        pair<int, int> now = q.front();
        q.pop();
        int y = now.first;
        int x = now.second;
        for (int i = 0; i < 4; i++)
        {
            int ny = y + yy[i];
            int nx = x + xx[i];
            if (ny < 0 || nx < 0 || ny >= col || nx >= row)
                continue;
            if (tomato[ny][nx] == -1 || tomato[ny][nx] >= 1) // tomato[ny][nx] >= 1
                continue;
            q.push(make_pair(ny, nx));
            tomato[ny][nx] = tomato[y][x] + 1;
            max_date = max(max_date, tomato[ny][nx]);
        }
    }
    return max_date;
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int input;

    cin >> row >> col;
    tomato = vector<vector<int>>(col, vector<int>(row, 0));
    for (int i = 0; i < col; i++)
        for (int j = 0; j < row; j++)
        {
            cin >> input;
            tomato[i][j] = input;
            if (input == 1)
                q.push(make_pair(i, j));
        }

    if (q.empty())
        cout << -1;
    else
    {
        int ans = BFS();

        for (int i = 0; i < col; i++)
        {
            for (int j = 0; j < row; j++)
            {
                if (tomato[i][j] == 0)
                {
                    cout << -1;
                    return 0;
                }
            }
        }
        if (ans == 1)
            cout << 0;
        else
            cout << ans - 1;
    }
    return 0;
}
