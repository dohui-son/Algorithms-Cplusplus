#include <bits/stdc++.h>
using namespace std;

int n, e, a, b, c, v1, v2, ans = 987654321, dist[804], res;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
vector<pair<int, int> > adj[804];

int dijk(int start, int dest)
{
    fill(dist, dist + 804, 987654321);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push({0, start});
    dist[start] = 0;
    while (pq.size())
    {
        int here = pq.top().second;
        int hd = pq.top().first;
        pq.pop();
        if (dist[here] != hd)
            continue;
        for (pair<int, int> there : adj[here])
        {
            int thd = there.first;
            int nth = there.second;
            if (dist[nth] > dist[here] + thd)
            {
                dist[nth] = dist[here] + thd;
                pq.push({dist[nth], nth});
            }
        }
    }
    return dist[dest];
}

int ruler(int &f, int &s)
{
    uint64_t ret = dijk(1, f) + dijk(f, s) + dijk(s, n);
    if (ret >= 987654321)
        return 987654321;
    return ret;
}

int main()
{
    scanf("%d %d", &n, &e);
    for (int i = 1; i <= e; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    scanf("%d %d", &v1, &v2);
    int ans = min(ruler(v1, v2), ruler(v2, v1));
    if (ans == 987654321)
        printf("-1\n");
    else
        printf("%d\n", ans);

    return 0;
}
