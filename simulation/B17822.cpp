#include <bits/stdc++.h> //큰돌코드
using namespace std;
#define y fuck
int n, m, T, x, d, k, a[54][54], ret, visited[54][54], y;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

bool flag = 1;
void _rotate(int y, int dir, int k)
{
    vector<int> v;
    for (int i = 0; i < m; i++)
        v.push_back(a[y][i]);
    if (dir == 1)
        rotate(v.begin(), v.begin() + k, v.end());
    else
        rotate(v.begin(), v.begin() + m - k, v.end());
    for (int i = 0; i < m; i++)
        a[y][i] = v[i];
    return;
}
void dfs(int y, int x)
{
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = (x + dx[i] + m) % m;
        if (ny < 0 || ny >= n)
            continue;
        if (visited[ny][nx])
            continue;
        if (a[y][x] == a[ny][nx])
        {
            visited[y][x] = visited[ny][nx] = 1;
            flag = 0;
            dfs(ny, nx);
        }
    }
}
bool findAdj()
{
    flag = 1;
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 0)
                continue;
            if (visited[i][j])
                continue;
            dfs(i, j);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j])
                a[i][j] = 0;
        }
    }
    return flag;
}
void setAverage()
{
    int sum = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 0)
                continue;
            sum += a[i][j];
            cnt++;
        }
    }
    double av = (double)sum / (double)cnt;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 0)
                continue;
            if ((double)a[i][j] > av)
                a[i][j]--;
            else if ((double)a[i][j] < av)
                a[i][j]++;
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> T;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < T; i++)
    {
        cin >> x >> d >> k;
        for (int j = x - 1; j < n; j += x)
        {
            _rotate(j, d, k);
        }
        if (findAdj())
            setAverage();
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ret += a[i][j];
        }
    }
    cout << ret << "\n";
    return 0;
}

// #include <iostream> //////////도희 정답
// #include <vector>
// #include <algorithm>
// #include <queue>

// #define endl '\n'
// using namespace std;
// int n, m, t, d, xx, kk, ans;
// struct Cmd
// {
//     int x, d, k;
// };
// vector<Cmd> input;
// vector<vector<int> > cir;
// int dy[] = {-1, 0, 1, 0};
// int dx[] = {0, 1, 0, -1};

// void average()
// {
//     float sum = 0, cnt = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {

//             if (cir[i][j])
//             {
//                 sum += (float)cir[i][j];
//                 cnt++;
//             }
//         }
//     }
//     sum /= cnt;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (!cir[i][j])
//                 continue;
//             if ((float)cir[i][j] > sum)
//             {
//                 cir[i][j]--;
//             }
//             else if ((float)cir[i][j] < sum)
//             {
//                 cir[i][j]++;
//             }
//         }
//     }
// }

// int bfs(int idx)
// { // 변화가 있으면 true
//     vector<vector<int> > visit(n, vector<int>(m, 0));
//     vector<pair<int, int> > change;
//     int ret = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (!visit[i][j] && cir[i][j])
//             {
//                 queue<pair<int, int> > q;
//                 q.push({i, j});
//                 visit[i][j] = 1;
//                 while (!q.empty())
//                 {
//                     int x = 0, y = 0;
//                     tie(y, x) = q.front();
//                     q.pop();
//                     for (int dd = 0; dd < 4; dd++)
//                     {
//                         int ny = dy[dd] + y;
//                         int nx = dx[dd] + x;
//                         if (ny >= n || ny < 0)
//                             continue;
//                         if (nx >= m || nx < 0)
//                         {
//                             if (nx > 0)
//                                 nx %= m;
//                             else
//                                 nx += m;
//                         }
//                         if (visit[ny][nx] || cir[ny][nx] == 0)
//                             continue;
//                         if (cir[ny][nx] == cir[y][x])
//                         {
//                             change.push_back({ny, nx});
//                             change.push_back({y, x});
//                             visit[ny][nx] = 1;
//                             q.push({ny, nx});
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     if (!change.empty())
//     {
//         ret = 1;
//         for (int i = 0; i < change.size(); i++)
//         {
//             cir[change[i].first][change[i].second] = 0;
//         }
//     }
//     return ret;
// }

// void rotation(int idx)
// {                           // input idx
//     int dir = input[idx].d; // 0정방향 / 1 역방향

//     for (int ii = 0; ii < input[idx].k; ii++)
//     {
//         for (int i = input[idx].x; i <= n; i += input[idx].x)
//         {
//             if (dir)
//             {
//                 rotate(cir[i - 1].begin(), cir[i - 1].begin() + 1, cir[i - 1].end());
//             }
//             else
//             { //정방향
//                 rotate(cir[i - 1].begin(), cir[i - 1].begin() + cir[i - 1].size() - 1, cir[i - 1].end());
//             }
//         }
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     cin >> n >> m >> t;
//     cir = vector<vector<int> >(n, vector<int>(m, 0));
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             cin >> cir[i][j];
//         }
//     }

//     input = vector<Cmd>(t);
//     for (int i = 0; i < t; i++)
//     {
//         cin >> input[i].x >> input[i].d >> input[i].k;
//     }
//     for (int i = 0; i < t; i++)
//     {
//         rotation(i);
//         if (bfs(i))
//         {
//             continue;
//         }
//         else
//             average();
//     }
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             ans += cir[i][j];
//         }
//     }
//     cout << ans;

//     return 0;
// }