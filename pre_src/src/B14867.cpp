#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int a, b, c, d;
queue<pair<int, int> > q;
map<pair<int, int>, int> m;
void enque(int x, int y, int cnt)
{
    if (m[{x, y}])
        return;
    q.push({x, y});
    m[{x, y}] = cnt + 1;
}

int bfs(int x, int y)
{
    m[{x, y}] = 1;
    q.push({x, y});
    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        enque(x, 0, m[{x, y}]);
        enque(0, y, m[{x, y}]);
        enque(a, y, m[{x, y}]);
        enque(x, b, m[{x, y}]);
        enque(max(0, x + y - b), min(b, x + y), m[{x, y}]); //a -> b
        enque(min(x + y, a), max(0, x + y - a), m[{x, y}]); // b - > a
    }
    if (m[{c, d}])
        return m[{c, d}] - 1;
    else
        return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> a >> b >> c >> d;
    cout << bfs(0, 0) << endl;

    return 0;
}
