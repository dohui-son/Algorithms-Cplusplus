#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
int n, m, answer = INF, isempty;
int g[51][51], time[51][51], check[10];
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
vector<pair<int, int> > virus;
queue<pair<int, int> > q;

void combi(int idx, int cnt)
{
    if (cnt == m)
    {
        memset(time, -1, sizeof(time));
        for (int i = 0; i < virus.size(); i++)
        {
            /* code */
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
            if (!g[i][j])
                isempty++;
            else if (g[i][j] == 2)
                virus.push_back({i, j});
        }
    }

    combi(0, 0);
    if (answer == INF)
        cout << -1 << "\n";
    else
        cout << answer << "\n";

    return 0;
}