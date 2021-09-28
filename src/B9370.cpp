// //<1>dijkstra 한번
// // a에서 b로의 최단거리를 d(a,b)라고 합시다.
// // 간선 gh를 사용한 최단경로가 존재한다면, d(s,g) + d(g,h) + d(h,t) = d(s,t)일 것입니다.
// // 간선 hg를 사용한 최단경로가 존재한다면, d(s,h) + d(h,g) + d(g,t) = d(s,t)일 것입니다.
// // 그러므로 s, g, h에서 다익스트라 알고리즘을 한 번씩 돌려 준 뒤, 각 후보지 t가 두 식 중 적어도 하나를 만족하는지 보면 됩니다.
// //<2>dijkstra 두번
// // 모든 간선의 비용을 두 배로 늘린 뒤, 점선의 비용을 1 줄입니다.
// // 그 상태에서 다익스트라를 돌려 준 뒤, 각 후보지의 최단거리가 홀수인지 보는 것도 좋습니다.
// #include <bits/stdc++.h>
// #define INF 0x7fffffff - 1
// using namespace std;
// priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
// int T, t, n, m, s, h, g, a, b, d, tmp, cur, graph[2001][2001], goal[2001], dist[2001];
// int main()
// {
//     scanf("%d", &T);
//     while (T--)
//     {
//         for (int i = 1; i <= n; i++)
//         {
//             goal[i] = 0;
//             dist[i] = 0;
//             for (int j = 1; j <= n; j++)
//                 graph[i][j] = 0;
//         }
//         scanf("%d%d%d%d%d%d", &n, &m, &t, &s, &g, &h);
//         while (m--)
//         {
//             scanf("%d%d%d", &a, &b, &d);
//             if ((a == g && b == h) || (a == h && b == g))
//                 graph[a][b] = graph[b][a] = 2 * d - 1;
//             else
//                 graph[a][b] = graph[b][a] = 2 * d;
//         }
//         while (t--)
//         {
//             scanf("%d", &tmp);
//             goal[tmp] = 1;
//         }
//         for (int i = 1; i <= n; i++)
//             dist[i] = INF;
//         pq.push({0, s});
//         dist[s] = 0;
//         while (!pq.empty())
//         {
//             int distance = pq.top().first;
//             int cur = pq.top().second;
//             pq.pop();
//             if (distance > dist[cur])
//                 continue;
//             for (int i = 1; i <= n; i++)
//             {
//                 if ((dist[i] > dist[cur] + graph[i][cur]) && graph[i][cur])
//                 {
//                     dist[i] = dist[cur] + graph[i][cur];
//                     pq.push({dist[i], i});
//                 }
//             }
//         }
//         for (int i = 1; i <= n; i++)
//             if (goal[i] && (dist[i] % 2))
//                 printf("%d ", i);
//         printf("\n");
//     }
// }

#include <bits/stdc++.h> //맞음
using namespace std;
#define INF 0x7fffffff - 1
int T, n, m, t, s, gg, h, a, b, d, x;
int dist[2001];
vector<int> hoobo;
vector<vector<int> > g;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
void dijik()
{
    fill(&dist[0], &dist[0] + 2001, INF);
    dist[s] = 0;
    pq.push({0, s});
    while (pq.size())
    {
        int dis = pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if (dist[here] < dis)
            continue;
        for (int i = 1; i < n + 1; i++)
        {
            if (g[i][here] && (dist[i] > dist[here] + g[i][here]))
            {
                dist[i] = dist[here] + g[i][here];
                pq.push({dist[i], i});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;
    while (T--)
    {
        cin >> n >> m >> t >> s >> gg >> h;
        g = vector<vector<int> >(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b >> d;
            if ((a == h && b == gg) || (a == gg && b == h))
            {
                g[a][b] = g[b][a] = 2 * d - 1;
            }
            else
            {
                g[a][b] = 2 * d;
                g[b][a] = 2 * d;
            }
        }
        for (int i = 0; i < t; i++)
        {
            cin >> x;
            hoobo.push_back(x);
        }
        dijik();

        sort(hoobo.begin(), hoobo.end());
        for (int i = 0; i < t; i++)
        {
            if (dist[hoobo[i]] != INF && (dist[hoobo[i]] % 2))
                cout << hoobo[i] << " ";
        }
        cout << "\n";
        hoobo.clear();
        g.clear();
    }
    return 0;
}