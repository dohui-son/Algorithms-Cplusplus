#include <stdio.h> //숏코딩
#include <string.h>
int dy[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dx[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int map[4][4];
int ans = 0;
struct info
{
    int y, x, d;
    int dead;
};
info fish[17];
void dfs(int y, int x, int s)
{
    int i;
    if (y < 0 || y >= 4 || x < 0 || x >= 4)
        return;
    if (map[y][x] == 0)
    {
        if (ans < s)
            ans = s;
        return;
    }
    int dir = fish[map[y][x]].d;
    s += map[y][x];
    fish[map[y][x]].dead = 1;
    map[y][x] = 0;
    info cf[17];
    int cm[4][4];
    for (i = 1; i < 17; i++)
    {
        if (fish[i].dead)
            continue;
        int &d = fish[i].d;
        int &fy = fish[i].y;
        int &fx = fish[i].x;
        while (fy + dy[d] < 0 || fy + dy[d] >= 4 || fx + dx[d] < 0 || fx + dx[d] >= 4 || (fy + dy[d] == y && fx + dx[d] == x))
        {
            d = d % 8 + 1;
        }
        fish[map[fy + dy[d]][fx + dx[d]]] = {fy, fx, fish[map[fy + dy[d]][fx + dx[d]]].d, 0};
        map[fy][fx] = map[fy + dy[d]][fx + dx[d]];
        fy += dy[d];
        fx += dx[d];
        map[fy][fx] = i;
    }
    memcpy(cm, map, sizeof(map));
    memcpy(cf, fish, sizeof(fish));
    for (i = 0; i < 4; i++)
    {
        dfs(y + i * dy[dir], x + i * dx[dir], s);
        memcpy(map, cm, sizeof(map));
        memcpy(fish, cf, sizeof(fish));
    }
}
int main()
{
    int i, j, dist;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            scanf("%d %d", &map[i][j], &dist);
            fish[map[i][j]] = {i, j, dist, 0};
        }
    }
    dfs(0, 0, 0);
    printf("%d\n", ans);
}