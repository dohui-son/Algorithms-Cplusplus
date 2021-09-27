#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int T, t, n, m, s, g, h, a, b, d, x, dist[50001];
vector<int> visited;

void dijk(vector<pair<int, int> > adj[2001], vector<uint64_t> &visited)
{
    fill(&dist[0], &dist[0] + 50001, INF);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push({0, s});
    visited[s] = (1 << s);
    dist[s] = 0;
    while (pq.size())
    {
        int now_d = pq.top().first;
        int here = pq.top().second;
        visited[here] |= (1 << here);
        pq.pop();
        if (dist[here] != now_d)
            continue;
        for (pair<int, int> next_ : adj[here])
        {
            int dis = next_.first;
            int there = next_.second;
            if (dist[there] > dist[here] + dis)
            {
                visited[there] |= visited[here];

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
        vector<uint64_t> visited(n + 1, 0);
        dijk(adj, visited);
        for (int ho : hoobo)
        {
            if (visited[ho] & (1 << g) && visited[ho] & (1 << h) && dist[ho] != INF)
                cout << ho << " ";
        }
        cout << "\n";
        visited.clear();
    }

    return 0;
}

//숏코딩
// #include <bits/stdc++.h>
// #define INF 0x7fffffff-1
// using namespace std;
// priority_queue<pair<int,int> >pq;
// int T,t,n,m,s,h,g,a,b,d,tmp,cur,graph[2001][2001],goal[2001],dist[2001];
// int main(){
// 	scanf("%d",&T);
// 	while(T--){
// 		for(int i=1;i<=n;i++) {
// 			goal[i]=0;
// 			dist[i]=0;
// 			for(int j=1;j<=n;j++) graph[i][j]=0;
// 		}
// 		scanf("%d%d%d%d%d%d",&n,&m,&t,&s,&g,&h);
// 		while(m--){
// 			scanf("%d%d%d",&a,&b,&d);
// 			if((a==g&&b==h)||(a==h&&b==g)) graph[a][b]=graph[b][a]=2*d-1;
// 			else graph[a][b]=graph[b][a]=2*d;
// 		}
// 		while(t--){
// 			scanf("%d",&tmp);
// 			goal[tmp]=1;
// 		}
// 		for(int i=1;i<=n;i++) dist[i]=INF;
// 		pq.push({0,s});
// 		dist[s]=0;
// 		while(!pq.empty()){
// 			int distance=-pq.top().first;
// 			int cur=pq.top().second;
// 			pq.pop();
// 			if(distance>dist[cur])continue;
// 			for(int i=1;i<=n;i++){
// 				if((dist[i]>dist[cur]+graph[i][cur])&&graph[i][cur]){
// 					dist[i]=dist[cur]+graph[i][cur];
// 					pq.push({-dist[i],i});
// 				}
// 			}
// 		}
// 		for(int i=1;i<=n;i++) if(goal[i]&&(dist[i]%2)) printf("%d ",i);
// 		printf("\n");
// 	}
// }