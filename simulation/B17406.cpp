#include <bits/stdc++.h>
using namespace std;
#define s second
#define f first
const int INF = 987654321;
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
int n, m, k, a[104][104], b[104][104], ret = INF, r, c, s, visited[104][104], dir, sy, sx, ey, ex;
vector<pair<int, int> > vv;
vector<int> v_idx;
struct A
{
    int y, x, cnt;
};
vector<A> v;
// bool cmp(A & a, A & b){
// 	if(a.y == b.y) return a.x < b.x;
// 	return a.y < b.y;
// }
void go(int y, int x, int first)
{
    if (!first && y == sy && x == sx)
        dir++;
    if (!first && y == sy && x == ex)
        dir++;
    if (!first && y == ey && x == ex)
        dir++;
    if (!first && y == ey && x == sx)
        dir++;
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    if (visited[ny][nx])
        return;
    visited[ny][nx] = 1;
    vv.push_back({ny, nx});
    go(ny, nx, 0);
}
void rotateAll(int y, int x, int cnt)
{
    for (int i = 1; i <= cnt; i++)
    {
        sy = y - 1 * i;
        sx = x - 1 * i;
        ey = y + 1 * i;
        ex = x + 1 * i;
        vv.clear();
        dir = 0;
        memset(visited, 0, sizeof(visited));
        visited[sy][sx] = 1;
        vv.push_back({sy, sx});
        go(sy, sx, 1);
        vector<int> vvv;
        for (pair<int, int> c : vv)
            vvv.push_back(b[c.f][c.s]);
        rotate(vvv.begin(), vvv.begin() + vvv.size() - 1, vvv.end());
        for (int i = 0; i < vv.size(); i++)
            b[vv[i].f][vv[i].s] = vvv[i];
    }
}
int solve()
{
    for (int i : v_idx)
        rotateAll(v[i].y, v[i].x, v[i].cnt);
    int _ret = INF;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < m; j++)
            cnt += b[i][j];
        _ret = min(_ret, cnt);
    }
    return _ret;
}
int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < k; i++)
    {
        cin >> r >> c >> s;
        r--;
        c--;
        v.push_back({r, c, s});
        v_idx.push_back(i);
    }
    do
    {
        memcpy(b, a, sizeof(b));
        ret = min(ret, solve());
    } while (next_permutation(v_idx.begin(), v_idx.end()));
    cout << ret << "\n";
    return 0;
}
// #include <iostream> //디버깅 실패
// #include <vector>
// #include <algorithm>
// #include <tuple>
// #define endl "\n"
// using namespace std;
// int n, m, k, r, c, s, ans = 987654321, tmp;
// vector<tuple<int, int, int> > kk;
// vector<vector<int> > b, a;
// int dy[] = {1, 0, -1, 0};
// int dx[] = {0, 1, 0, -1};

// void rot(int kdx, vector<vector<int> > &aa)
// {
//     tie(r, c, s) = kk[kdx]; // 돌리는 행위 s번 만큼하면 됨

//     int sy = r - s, sx = c - s;
//     while (s--)
//     {
//         int cnt = 4, y = sy, x = sx;
//         tmp = aa[sy][sx];
//         while (cnt < 5)
//         {
//             int ny = dy[cnt] + y;
//             int nx = dx[cnt] + x;
//             if (ny == sy && nx == sx)
//             {
//                 aa[y][x] = tmp;
//                 break;
//             }
//             aa[y][x] = aa[ny][nx];
//             ny = y;
//             nx = x;
//             if (ny == r - 2 || nx == c - 2 || ny == r + 2 || nx == c + 2)
//                 cnt++;
//         }
//         sy++, sx++;
//     }
// }
// void BT(int start, int here, vector<vector<int> > &aa)
// {

//     if (here == k)
//     {
//         for (int i = 0; i < n; i++)
//         {
//             int tmp = 0;
//             for (int j = 0; j < m; j++)
//             {
//                 tmp += aa[i][j];
//             }
//             ans = min(ans, tmp);
//         }
//         return;
//     }

//     for (int i = start; i < k; i++)
//     {
//         b = aa;
//         BT(i + 1, here + 1, b);
//         rot(i, aa);
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     cin >> n >> m >> k;
//     a = vector<vector<int> >(n + 1, vector<int>(m + 1, 0));
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             cin >> a[i][j];
//         }
//     }
//     for (int i = 0; i < k; i++)
//     {
//         cin >> r >> c >> s;
//         kk.push_back({r, c, s});
//     }
//     BT(0, 0, a);
//     cout << ans << endl;
//     return 0;
// }
