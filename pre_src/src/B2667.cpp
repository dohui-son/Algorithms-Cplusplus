//입력때문에 오래걸렸었음
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
//#include "../print.hpp"

#define endl "\n";

using namespace std;
int N, idx;
queue<pair<int, int>> q;
vector<vector<int>> house;
vector<vector<bool>> visit;
vector<int> ans;

int BFS()
{
    int idx = 0;

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {

            if (house[y][x] && !visit[y][x])
            {

                ans.push_back(0);
                q.push(make_pair(y, x));
                visit[y][x] = true;
                while (!q.empty())
                {
                    pair<int, int> tmp_pair = q.front();
                    int now_y = tmp_pair.first;
                    int now_x = tmp_pair.second;
                    q.pop();
                    ans[idx]++;

                    if (now_x < N - 1 && house[now_y][now_x + 1] && !visit[now_y][now_x + 1])
                    {
                        q.push(make_pair(now_y, now_x + 1));
                        visit[now_y][now_x + 1] = true;
                    }
                    if (now_y < N - 1 && house[now_y + 1][now_x] && !visit[now_y + 1][now_x])
                    {
                        q.push(make_pair(now_y + 1, now_x));
                        visit[now_y + 1][now_x] = true;
                    }
                    if (0 < now_x && house[now_y][now_x - 1] && !visit[now_y][now_x - 1])
                    {
                        q.push(make_pair(now_y, now_x - 1));
                        visit[now_y][now_x - 1] = true;
                    }
                    if (0 < now_y && house[now_y - 1][now_x] && !visit[now_y - 1][now_x])
                    {
                        q.push(make_pair(now_y - 1, now_x));
                        visit[now_y - 1][now_x] = true;
                    }
                }
                idx++;
            }
        }
    }

    return idx;
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> N;

    house = vector<vector<int>>(N, vector<int>(N, 0));
    visit = vector<vector<bool>>(N, vector<bool>(N, false));
    //ans = vector<int>(N * N, 0);

    char input;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> input;
            if (input == '1')
                house[i][j] = 1;
        }
    }

    int index = BFS();
    cout << index << endl;

    sort(ans.begin(), ans.end());

    for (int i = 0; i < index; i++)
        cout << ans[i] << endl;
    //cout << house;

    return 0;
}