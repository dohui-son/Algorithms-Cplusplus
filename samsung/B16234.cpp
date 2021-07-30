#include <bits/stdc++.h> //시간 80ms
using namespace std;

int visited[54][54];
int a[54][54];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int n, l, r, sum, cnt;

vector<pair<int, int> > v;

void dfs(int y, int x, vector<pair<int, int> > &v)
{
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[ny][nx])
            continue;
        if (abs(a[ny][nx] - a[y][x]) >= l && abs(a[ny][nx] - a[y][x]) <= r)
        {
            visited[ny][nx] = 1;
            v.push_back({ny, nx});
            sum += a[ny][nx];
            dfs(ny, nx, v);
        }
    }
}

int main()
{
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    while (true)
    {
        bool flag = 0;
        fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j])
                {
                    v.clear();
                    visited[i][j] = 1;
                    v.push_back({i, j});
                    sum = a[i][j];
                    dfs(i, j, v);
                    if (v.size() == 1)
                        continue;
                    for (pair<int, int> b : v)
                    {
                        a[b.first][b.second] = sum / v.size();
                        flag = 1;
                    }
                }
            }
        }
        if (!flag)
            break;
        cnt++;
    }
    cout << cnt << "\n";
    return 0;
}

/////////////////////////////////////손도희 코드 --- 시간 차이가 크다!!!!!!시간 520
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <queue>
// #define endl "\n"
// using namespace std;

// int n, l, r, ans, rr, cc;
// int g[51][51];
// int dy[] = {0, 1, 0, -1};
// int dx[] = {1, 0, -1, 0};
// //vector<vector<int> > visit(51, vector<int>(51, 0));
// int visit[51][51], summ[51][51];

// void bfs(int y, int x, vector<pair<int, int> > &c)
// {
//     queue<pair<int, int> > q;
//     q.push({y, x});
//     summ[y][x] = g[y][x];
//     int xx = 0, yy = 0;
//     while (q.size())
//     {
//         tie(yy, xx) = q.front();
//         q.pop();
//         for (int i = 0; i < 4; i++)
//         {
//             int ny = dy[i] + yy;
//             int nx = dx[i] + xx;
//             if (ny < 0 || nx < 0 || ny >= n || nx >= n || visit[ny][nx])
//                 continue;
//             int tmp = abs(g[yy][xx] - g[ny][nx]);
//             if (l <= tmp && tmp <= r && !visit[ny][nx])
//             {
//                 visit[yy][xx] = 1;
//                 c.push_back({ny, nx});
//                 visit[ny][nx] = 1;
//                 q.push({ny, nx});
//                 summ[y][x] += g[ny][nx];
//             }
//         }
//     }
// }
// bool populate()
// {
//     bool ret = true; //인구이동 안일어남

//     fill(&visit[0][0], &visit[0][0] + 51 * 51, 0);
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (!visit[i][j])
//             {
//                 visit[i][j] = 1;
//                 vector<pair<int, int> > ch;
//                 ch.push_back({i, j});
//                 bfs(i, j, ch);

//                 if (ch.size() > 1)
//                 {
//                     ret = false;
//                     summ[i][j] /= ch.size();
//                     for (int dd = 0; dd < ch.size(); dd++)
//                     {
//                         g[ch[dd].first][ch[dd].second] = summ[i][j];
//                     }
//                 }
//             }
//         }
//     }

//     return ret;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     cin >> n >> l >> r;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cin >> g[i][j];
//         }
//     }

//     while (1)
//     {
//         if (populate())
//             break;
//         if (ans > 4000)
//             break;
//         ans++;
//     }
//     cout << ans << endl;

//     return 0;
// }
