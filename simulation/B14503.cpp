#include <bits/stdc++.h>
using namespace std;

int simulate(int y, int x, int d)
{
    int ret = 0;
    if (!visited[y][x])
    {
        visited[y][x] = 1;
        ret++;
    }
    if (isAllFin(y, x))
    {
        back_d = (d + 2) % 4;
        back_y = y + dy[back_d];
        back_x = x + dx[back_d];
        //후진도 못할 경우 바로 리턴, 그게 아니라면 방향을 유지한채 후진을 합니다.
        if (back_y < 0 || back_y >= n || back_x < 0 || back_x >= m || a[back_y][back_x] == 1)
            return ret;
        return ret += simulate(back_y, back_x, d);
    }
    left_d = (d + 3) % 4;
    left_y = y + dy[left_d];
    left_x = x + dx[left_d];
    if (left_y < 0 || left_y >= n || left_x < 0 || left_x >= m)
        return ret;
    // 왼쪽이 방문가능하다면 그 쪽으로 방문하고 그게 아니라면 y,x를 유지한채 왼쪽으로 회전합니다.
    if (!visited[left_y][left_x] && a[left_y][left_x] == 0)
        ret += simulate(left_y, left_x, left_d);
    else if (visited[left_y][left_x] || a[left_y][left_x] == 1)
        ret += simulate(y, x, left_d);
    return ret;
}
//아래의 지문은

​

    //네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.

    //네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.

    //아래의 코드로 변환됩니다.

    if (isAllFin(y, x))
{
    back_d = (d + 2) % 4;
    back_y = y + dy[back_d];
    back_x = x + dx[back_d];
    //후진도 못할 경우 바로 리턴, 그게 아니라면 방향을 유지한채 후진을 합니다.
    if (back_y < 0 || back_y >= n || back_x < 0 || back_x >= m || a[back_y][back_x] == 1)
        return ret;
    return ret += simulate(back_y, back_x, d);
}

int main()
{
    return 0;
}