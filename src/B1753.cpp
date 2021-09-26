#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int V, E, k, u, v, w;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
vector<pair<int, int> > adj[20002];
int dist[20002];

void dijk()
{
    pq.push({0, k});
    dist[k] = 0;
    while (pq.size())
    {
        int here = pq.top().second;
        int h_dist = pq.top().first;
        pq.pop();
        if (dist[here] != h_dist)
            continue;
        for (pair<int, int> there : adj[here])
        {
            int _dist = there.first;
            int _there = there.second;
            if (dist[_there] > dist[here] + _dist)
            {
                dist[_there] = dist[here] + _dist;
                pq.push({dist[_there], _there});
            }
        }
    }
}

int main()
{
    fill(dist, dist + 20002, INF);
    scanf("%d %d %d", &V, &E, &k);
    for (int i = 0; i < E; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back({w, v});
    }
    dijk();
    for (int i = 1; i <= V; i++)
    {
        if (dist[i] == INF)
            printf("INF\n");
        else
            printf("%d\n", dist[i]);
    }
    return 0;
}
