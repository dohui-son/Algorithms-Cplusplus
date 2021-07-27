#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define endl "\n"
using namespace std;
#define max_n 104
struct Shark
{
    int x, y, s, z, dir, death;
} a[max_n * max_n];
const int dx[] = {0, 0, 0, 1, -1};
const int dy[] = {0, -1, 1, 0, 0};
int _map[max_n][max_n], R, C, M, ret, temp[max_n][max_n];
int main()
{
    cin >> R >> C >> M;
    for (int i = 1; i <= M; i++)
    {
        cin >> a[i].y >> a[i].x >> a[i].s >> a[i].dir >> a[i].z;
        a[i].y -= 1;
        a[i].x -= 1;
        _map[a[i].y][a[i].x] = i;
    }
    for (int t = 0; t < C; t++)
    {
        for (int y = 0; y < R; y++)
        {
            if (_map[y][t])
            {
                a[_map[y][t]].death = 1;
                ret += a[_map[y][t]].z;
                _map[y][t] = 0;
                break;
            }
        }
        //memset(temp, 0, sizeof(temp));
        fill(&temp[0][0], &temp[0][0] + max_n * max_n, 0);
        for (int i = 1; i <= M; i++)
        {
            if (a[i].death)
                continue;
            int _y = a[i].y, _x = a[i].x, s = a[i].s, d = a[i].dir, ny = 0, nx = 0;
            while (1)
            {
                ny = _y + s * dy[d];
                nx = _x + s * dx[d];
                if (nx < C && ny < R && ny >= 0 && nx >= 0)
                    break;
                if (d == 1 && ny < 0)
                {
                    s -= _y;
                    _y = 0;
                    d = 2;
                }
                else if (d == 2 && ny >= R)
                {
                    s -= R - 1 - _y;
                    _y = R - 1;
                    d = 1;
                }
                else if (d == 3 && nx >= C)
                {
                    s -= C - 1 - _x;
                    _x = C - 1;
                    d = 4;
                }
                else if (d == 4 && nx < 0)
                {
                    s -= _x;
                    _x = 0;
                    d = 3;
                }
            }
            if (temp[ny][nx])
            {
                if (a[temp[ny][nx]].z < a[i].z)
                {
                    a[temp[ny][nx]].death = 1;
                    temp[ny][nx] = i;
                }
                else
                    a[i].death = 1;
            }
            else
                temp[ny][nx] = i;
            a[i].x = nx;
            a[i].y = ny;
            a[i].dir = d;
        }
        for (int y = 0; y < R; y++)
        {
            for (int x = 0; x < C; x++)
                _map[y][x] = temp[y][x];
        }
    }
    cout << ret << "\n";
    return 0;
}
