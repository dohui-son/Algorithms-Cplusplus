#include <iostream>
#include <set>
#include <tuple>
using namespace std;
using ll = long long;

int n = 0, b[404] = {
               0,
},
    c[22][22], ans = 0;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
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
            int a = 1;
            cin >> a;
            s[b[i]].insert(a);
        }
    }
    for (int i = 0; i <= n + 1; i++)
        c[0][i] = c[n + 1][i] = c[i][0] = c[i][n + 1] = -1;
    for (int i = 1; i <= n * n; i++)
    {
        tuple<int, int, int, int> mx = {-1, 0, 0, 0};
        for (int x = 1; x <= n; x++)
        {
            for (int y = 1; y <= n; y++)
                if (!c[x][y])
                {
                    int c1 = 0, c2 = 0;
                    for (int d = 0; d < 4; d++)
                    {
                        int k = c[x + dx[d]][y + dy[d]];
                        if (s[b[i]].count(k))
                            c1++;
                        else if (k == 0)
                            c2++;
                    }
                    mx = max(mx, {c1, c2, -x, -y});
                }
        }
        auto [c1, c2, x, y] = mx;
        x = -x, y = -y;
        c[x][y] = b[i];
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            int c1 = 0;
            for (int d = 0; d < 4; d++)
                if (s[c[i][j]].count(c[i + dx[d]][j + dy[d]]))
                    c1++;
            ans += pw[c1];
        }
    cout << ans;
    return 0;
}
