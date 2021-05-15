//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <queue>
//
//using namespace std;
//#define endl '\n'
//
//const int MAX = 100000;
//int dist[MAX + 1];
//int64_t cnt[MAX + 1];
//int n, m;
//
//int main() {
//	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//	cin >> n >> m;
//	if (n == m) { cout << 0 << '\n' << 1; return 0; }
//
//	dist[n] = 0;
//	cnt[n] = 1;
//
//	queue<int> q;
//	q.push(n);
//	while (!q.empty())
//	{
//		int now = q.front();
//		q.pop();
//		for (int next : {now-1,now+1,now*2})
//		{
//			if (0 <= next && next <= MAX) {
//				if (!dist[next]) { // 0ÀÌ¸י
//					q.push(next);
//					dist[next] = dist[now] + 1;
//					cnt[next] += cnt[now];
//				}
//				else if (dist[next] == dist[now] + 1)cnt[next] += cnt[now];
//			}
//		}
//	}
//	cout << dist[m] << '\n' << cnt[m];
//
//	return 0;
//}