#include <iostream>
#include <set>
#include <tuple>
using namespace std;
typedef long long ll;
int n = 0, ans = 0, b[404] = {
                        0,
},
    c[22][22];
const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {-1, 1, 0, 0};
const int pw[5] = {0, 1, 10, 100, 1000};
set<int> s[404];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n * n; i++)
    {
        cin >> b[i];
        for (int j = 1; j <= 4; j++)
        {
            int a = 0;
            cin >> a;
            s[b[i]].insert(a);
        }
    }
    for (int i = 0; i <= n + 1; i++)
        c[0][i] = c[n + 1][i] = c[i][0] = c[i][n + 1] = -1;
    for (int i = 1; i <= n * n; i++)
    {
        tuple<int, int, int, int> mx = {-1, 0, 0, 0};
        for (int y = 1; y <= n; y++)
        {
            for (int x = 1; x <= n; x++)
            {
                if (!c[y][x])
                {
                    int c1 = 0, c2 = 0;
                    for (int d = 0; d < 4; d++)
                    {
                        int k = c[y + dy[d]][x + dx[d]];
                        if (s[b[i]].count(k))
                            c1++;
                        else if (k == 0)
                            c2++;
                    }
                    mx = max(mx, {c1, c2, -y, -x});
                }
            }
        }
        auto [c1, c2, y, x] = mx;
        y = -y, x = -x;
        c[y][x] = b[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int cnt = 0;
            for (int d = 0; d < 4; d++)
            {
                if (s[c[i][j]].count(c[i + dy[d]][j + dx[d]]))
                    cnt++;
            }
            ans += pw[cnt];
        }
    }
    cout << ans;
    return 0;
}