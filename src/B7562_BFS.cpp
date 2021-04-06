#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

#define endl "\n";

using namespace std;
//DFS 불가능
int testcases, l, s_y, s_x, dest_y, dest_x;
queue<pair<int, int>> q;
int chess[301][301] = {
    0,
};

int yy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int xx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

void BFS()
{
    q.push(make_pair(s_y, s_x));
    while (!q.empty())
    {
        pair<int, int> now = q.front();
        q.pop();
        int now_y = now.first;
        int now_x = now.second;
        if (now_y == dest_y && now_x == dest_x)
        {

            cout << chess[now_y][now_x] << endl;
            while (!q.empty())
                q.pop();

            break;
        }
        for (int i = 0; i < 8; i++)
        {
            int next_y = yy[i] + now_y;
            int next_x = xx[i] + now_x;

            if (next_y < 0 || next_x < 0 || next_y >= l || next_x >= l || chess[next_y][next_x] > 0)
                continue;
     

            chess[next_y][next_x] = chess[now_y][now_x] + 1;
      
            q.push(make_pair(next_y, next_x));
   
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> testcases;

    for (int i = 0; i < testcases; i++)
    {
        cin >> l >> s_y >> s_x >> dest_y >> dest_x;
        BFS();
        memset(chess, 0, sizeof(chess));
    }

    return 0;
}