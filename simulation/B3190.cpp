#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#define endl "\n"
using namespace std;
typedef long long ll;
#define time ff
#define y1 cc

int n, k, l, y, x, t, ret, idx, dir = 1;
int a[104][104], visited[104][104], time;
char c;
deque<pair<int, int> > dq;
vector<pair<int, int> > _time;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> y >> x;
        a[--y][--x] = 1;
    }
    cin >> l;
    for (int i = 0; i < l; i++)
    {
        cin >> t >> c;
        if (c == 'D')
            _time.push_back({t, 1});
        else
            _time.push_back({t, 3});
    }
    dq.push_back({0, 0});
    visited[0][0] = 1;
    while (dq.size())
    {
        time++;
        tie(y, x) = dq.front();
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx])
            break;
        if (!a[ny][nx])
        {
            visited[dq.back().first][dq.back().second] = 0;
            dq.pop_back();
        }
        else
            a[ny][nx] = 0;
        visited[ny][nx] = 1;
        dq.push_front({ny, nx});
        if (time == _time[idx].first)
        {
            dir = (dir + _time[idx].second) % 4;
            idx++;
        }
    }
    cout << time << endl;
    return 0;
}

// ////도희 버전
// #include <iostream>
// #include <vector>
// #include <deque>
// #include <algorithm>
// #define endl '\n'
// using namespace std;

// int n, k, l, ans, idx, r, c;
// vector<pair<int, int> > cmd;
// vector<vector<int> > g;
// int dx[] = {0, 1, 0, -1};
// int dy[] = {-1, 0, 1, 0};
// char tmp;

// struct Bam
// {
//     deque<pair<int, int> > dq;
//     int d;
// };
// bool go(Bam &b)
// { //게임 끝나면 true를 리턴하기
//     int ny = dy[b.d] + b.dq.front().first;
//     int nx = dx[b.d] + b.dq.front().second;
//     if (ny < 0 || nx < 0 || ny >= n || nx >= n)
//         return true;
//     if (g[ny][nx] == 1)
//         return true;
//     if (g[ny][nx] == 0)
//     {
//         g[b.dq.back().first][b.dq.back().second] = 0;
//         b.dq.pop_back();
//     }
//     b.dq.push_front({ny, nx});
//     g[ny][nx] = 1;
//     return false;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     cin >> n >> k;
//     g = vector<vector<int> >(n + 1, vector<int>(n, 0));
//     g[0][0] = 1;
//     for (int i = 0; i < k; i++)
//     {
//         cin >> r >> c;
//         g[--r][--c] = 2;
//     }
//     cin >> l;
//     cmd = vector<pair<int, int> >(l);
//     for (int i = 0; i < l; i++)
//     {
//         cin >> r >> tmp;
//         cmd[i].first = r;
//         if (tmp == 'L')
//             cmd[i].second = 3; // 왼쪽이면 0
//         else
//             cmd[i].second = 1;
//     }
//     r = 0;
//     Bam b;
//     b.dq.push_front({0, 0});
//     g[0][0] = 1;
//     b.d = 1;
//     while (1)
//     {
//         ans++;
//         if (go(b))
//             break;
//         if (ans == cmd[idx].first)
//         {
//    b.d = (b.d+cmd[idx].second) % 4;
//             idx++;
//         }
//     }
//     cout << ans << endl;
//     return 0;
// }
