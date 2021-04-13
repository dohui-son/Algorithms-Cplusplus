//#include <iostream>
//#include <vector>
//#include <map>
//#include <algorithm>
//#include <queue>
//
//using namespace std;
//#define endl "\n"
//int V, E, K;
//vector<map<int, int>> v;
//vector<bool> visit;
//vector<int> di;
//priority_queue<pair<int,int>,vector<pair<int,int>>, comp()>pq;
//comp
//
////v[i] i번에서 출발하는 모든 간선들, vector<map<int,int>>v 맵의 첫번째 int는 도착점 
//// <도착점,가중치weight> vector의 i j 
//
//
//
//
//void D(int kk) {
//	
//	for (int  j = 0; j < di.size(); j++)
//	{
//		if (j == kk - 1)continue;
//		int smallest = 4000000;
//		int now_idx = 0;
//		for (int i = 0; i < di.size(); i++)
//		{
//			if (visit[i] == true)continue;
//
//
//
//
//
//		}
//	}
//
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//
//	cin >> V >> E >> K;
//	v = vector<map<int, int>>(V,map<int,int>());
//	visit = vector<bool>(V);
//	di = vector<int>(V,4000000);
//	int u, vv, w;
//	for (int i = 0; i < E; i++)
//	{
//		cin >> u >> vv >> w;
//		if (v[u - 1].find(vv-1) != v[u - 1].end()) {
//			v[u - 1].insert({ vv-1,w });
//		}
//		else {
//			v[u - 1][vv-1] = min(v[u - 1][vv-1], w);
//		}
//		if (u == K) { 
//			di[vv - 1] = w; 
//			pq.push(make_pair(w, vv - 1));
//		}
//	}
//	D(K);
//
//	return 0;
//}