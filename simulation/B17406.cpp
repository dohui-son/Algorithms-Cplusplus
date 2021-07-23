#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#define endl "\n"
using namespace std;
int n, m, k, r, c, s, ans = 987654321, tmp;
vector<tuple<int, int, int> > kk;
vector<vector<int> > b, a;
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

void rot(int kdx, vector<vector<int> > &aa)
{
    tie(r, c, s) = kk[kdx]; // 돌리는 행위 s번 만큼하면 됨

    int sy = r - s, sx = c - s;
    while (s--)
    {
        int cnt = 4, y = sy, x = sx;
        tmp = aa[sy][sx];
        while (cnt < 5)
        {
            int ny = dy[cnt] + y;
            int nx = dx[cnt] + x;
            if (ny == sy && nx == sx)
            {
                aa[y][x] = tmp;
                break;
            }
            aa[y][x] = aa[ny][nx];
            ny = y;
            nx = x;
            if (ny == r - 2 || nx == c - 2 || ny == r + 2 || nx == c + 2)
                cnt++;
        }
        sy++, sx++;
    }
}
void BT(int start, int here, vector<vector<int> > &aa)
{

    if (here == k)
    {
        for (int i = 0; i < n; i++)
        {
            int tmp = 0;
            for (int j = 0; j < m; j++)
            {
                tmp += aa[i][j];
            }
            ans = min(ans, tmp);
        }
        return;
    }

    for (int i = start; i < k; i++)
    {
        b = aa;
        BT(i + 1, here + 1, b);
        rot(i, aa);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> k;
    a = vector<vector<int> >(n + 1, vector<int>(m + 1, 0));
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
        kk.push_back({r, c, s});
    }
    BT(0, 0, a);
    cout << ans << endl;
    return 0;
}
