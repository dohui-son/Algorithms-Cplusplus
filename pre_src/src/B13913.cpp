//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <string>
//using namespace std;
//#define endl '\n'
//const int MAX = 100000;
//int n, k, dis[MAX + 1];
//vector<vector<int>> hist;
//
//
//int main() {
//	ios::sync_with_stdio(false); cin.tie(nullptr);cout.tie(nullptr);
//	cin >> n >> k;
//	if (n == k) { cout << 0; }
//	else {
//		queue<int>q;
//		//dis[n] = 0;
//		q.push(n);
//		//hist[n].push_back(n + '0');
//		
//		while (!q.empty())
//		{
//			int now = q.front(); q.pop();
//			for (int next : {now-1, now+1, now*2})
//			{
//				if (dis[k] != 0) {
//					string str = to_string(k);
//					hist[k].push_back(k);
//					
//					
//					cout << dis[k] << '\n';
//					for (int i = 0; i < hist[k].size(); i++)
//					{
//						cout << hist[k][i] << ' ';
//					}
//					return 0;
//				}
//				if (next >= 0 && next <= MAX) {
//					if (dis[next] == 0) {
//						q.push(next);
//						dis[next] = dis[now] + 1;
//						hist[next] = hist[now];
//						hist[next].push_back(now);
//					}
//				}
//
//			}
//
//		}
//
//	}
//
//	return 0;
//}