#include <bits/stdc++.h>

using namespace std;
#define endl "\n";
bool g[11][11], aa[11], visit[11];
int a, b, pop[11], ans = 987654321, n, num, total;
int bfs(bool now)
{
    int ret = 0;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (!visit[i] && aa[i] == now)
        {
            q.push(i);
            visit[i] = 1;
            ret += pop[i];
            break;
        }
    }
    while (q.size())
    {
        int turn = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (!visit[i] && g[turn][i] && aa[i] == now)
            {
                visit[i] = 1;
                ret += pop[i];
                q.push(i);
            }
        }
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> pop[i];
        total += pop[i];
    }
    int tmp = 0, idx = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        for (int j = 0; j < tmp; j++)
        {
            cin >> idx;
            idx--;
            g[i][idx] = 1;
            g[idx][i] = 1;
        }
    }
    for (int i = 1; i < (1 << n); i++)
    {
        fill(aa, aa + 11, false);
        fill(visit, visit + 11, false);
        a = b = num = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                num++;
                aa[j] = 1;
            }
        }
        if (num == n)
            continue;
        a = bfs(aa[0]);
        b = bfs(!aa[0]);
        if (a + b == total)
            ans = min(ans, abs(a - b));
    }
    if (ans != 987654321)
    {
        cout << ans << endl;
    }
    else
        cout << -1 << endl;

    return 0;
}