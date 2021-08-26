#include <bits/stdc++.h>
using namespace std;
#define y aaaa
int n, k, g[14][14], y, x, dir, ans;
struct Point
{
    int y, x, dir;
};
vector<int> a[14][14];
vector<Point> mal;
const int dy[] = {0, 0, 0, -1, 1};
const int dx[] = {0, 1, -1, 0, 0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
        }
    }
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < k; i++)
    {
        cin >> a >> b >> c;
        a--, b--;
        mal.push_back({a, b, c});
    }
    while (ans <= 1000)
    {
    }
    if (ans <= 1000)
        cout << ans << endl;
    else
        cout << -1 << endl;

    return 0;
}