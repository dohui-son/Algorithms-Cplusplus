#include <iostream> //shortest version
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pt;
int N, M, K, mmn = 9999, m[50][50], ck[50][50], v[10], dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
pt vpt[10];
queue<pt> q;

void sim()
{
    int i, j, mx = 1;
    for (i = 0; i < K; i++)
        if (v[i])
        {
            q.push(vpt[i]);
            ck[vpt[i].first][vpt[i].second] = 1;
        }
    while (!q.empty())
    {
        pt p = q.front();
        q.pop();

        for (i = 0; i < 4; i++)
        {
            int xx = p.first + dx[i], yy = p.second + dy[i];
            if (xx >= 0 && xx < N && yy >= 0 && yy < N && m[xx][yy] % 2 == 0 && !ck[xx][yy])
            {
                ck[xx][yy] = ck[p.first][p.second] + 1;
                q.push({xx, yy});
            }
        }
    }
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            if (!m[i][j])
                if (ck[i][j])
                    mx = max(mx, ck[i][j]);
                else
                    return;
    mmn = min(mmn, mx);
}

int main()
{
    int i, j;
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N >> M;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
        {
            cin >> m[i][j];
            if (m[i][j] > 1)
                vpt[K++] = {i, j};
        }
    for (i = 1; i <= M; i++)
        v[K - i] = 1;
    do
    {
        fill_n(&ck[0][0], 2500, 0);
        sim();
    } while (next_permutation(v, v + K));
    cout << (mmn > 9998 ? -1 : mmn - 1);
    return 0;
}