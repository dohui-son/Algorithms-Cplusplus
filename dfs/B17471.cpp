///참고용 숏코딩
#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, a[11], m, temp, ret = INF, comp[11], visited[11];
vector<int> adj[11];
pair<int, int> dfs(int here, int value)
{
    visited[here] = 1;
    pair<int, int> ret = {1, a[here]};
    for (int there : adj[here])
    {
        if (comp[there] != value)
            continue;
        if (visited[there])
            continue;
        pair<int, int> _temp = dfs(there, value);
        ret.first += _temp.first;
        ret.second += _temp.second;
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            cin >> temp;
            adj[i].push_back(temp);
            adj[temp].push_back(i);
        }
    }
    for (int i = 1; i < (1 << n) - 1; i++)
    {
        fill(comp, comp + 11, 0);
        fill(visited, visited + 11, 0);
        int idx1 = -1, idx2 = -1;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                comp[j + 1] = 1;
                idx1 = j + 1;
            }
            else
                idx2 = j + 1;
        }
        pair<int, int> comp1 = dfs(idx1, 1);
        pair<int, int> comp2 = dfs(idx2, 0);
        if (comp1.first + comp2.first == n)
            ret = min(ret, abs(comp1.second - comp2.second));
    }
    cout << (ret == INF ? -1 : ret) << "\n";
}
/////////////////
// #include <bits/stdc++.h>

// using namespace std;
// #define endl "\n";
// bool g[11][11], aa[11],v[11];
// int a, b, pop[11], ans = 987654321, n, num, total;
// int bfs(bool now)
// {
//     int ret = 0;
//     queue<int> q;
//     for (int i = 0; i < n; i++)
//     {
//         if (!v[i] && aa[i] == now)
//         {
//             q.push(i);
//             v[i] = 1;
//             ret += pop[i];
//             break;
//         }
//     }
//     while (q.size())
//     {
//         int turn = q.front();
//         q.pop();
//         for (int i = 0; i < n; i++)
//         {
//             if (!v[i] && g[turn][i] && aa[i] == now)
//             {
//                 v[i] = 1;
//                 ret += pop[i];
//                 q.push(i);
//             }
//         }
//     }
//     return ret;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> pop[i];
//         total += pop[i];
//     }
//     int tmp = 0, idx = 0;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> tmp;
//         for (int j = 0; j < tmp; j++)
//         {
//             cin >> idx;
//             idx--;
//             g[i][idx] = 1;
//             g[idx][i] = 1;
//         }
//     }
//     for (int i = 1; i < (1 << n); i++)
//     {
//         fill(aa, aa + 11, false);
//         fill(v, v + 11, false);
//         a = b = num = 0;
//         for (int j = 0; j < n; j++)
//         {
//             if (i & (1 << j))
//             {
//                 num++;
//                 aa[j] = 1;
//             }
//         }
//         if (num == n)
//             continue;
//         a = bfs(aa[0]);
//         b = bfs(!aa[0]);
//         if (a + b == total)
//             ans = min(ans, abs(a - b));
//     }
//     if (ans != 987654321)
//     {
//         cout << ans << endl;
//     }
//     else
//         cout << -1 << endl;

//     return 0;
// }