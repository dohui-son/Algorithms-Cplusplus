#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int T, t, n, m, s, g, h, a, b, d, x, dist[50001];
vector<int> visited;

void dijk(vector<pair<int, int> > adj[2001])
{
    fill(&dist[0], &dist[0] + 50001, INF);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >
        pq;
    pq.push({0, s});
    dist[s] = 0;
    while (pq.size())
    {
        int now_d = pq.top().first;
        int here = pq.top().second;
        if (dist[here] == now_d)
            continue;
        for (pair<int, int> next_ : adj[here])
        {
            int dis = next_.first;
            int there = next_.second;
            if (dist[there] > dist[here] + dis)
            {
                if ((here == g && there == h) || (here == h && there == g))
                    visited[there] = visited[here] = 1;
                visited[there] = visited[here];
                dist[there] = dist[here] + dis;
                pq.push({dist[there], there});
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
        cin >> n >> m >> t;
        vector<pair<int, int> > adj[2001];

        cin >> s >> g >> h;
        for (int i = 1; i <= m; i++)
        {
            cin >> a >> b >> d;
            adj[a].push_back({d, b});
            adj[b].push_back({d, a});
        }
        vector<int> hoobo;
        for (int i = 0; i < t; i++)
        {
            cin >> x;
            hoobo.push_back(x);
        }
        sort(hoobo.begin(), hoobo.end());
        visited = vector<int>(n + 1, 0);
        dijk(adj);

        for (int ho : hoobo)
        {
            if (visited[ho])
                cout << ho << " ";
        }
        cout << "\n";
        visited.clear();
    }

    return 0;
}