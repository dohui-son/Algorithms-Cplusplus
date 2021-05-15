//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <queue>
//#include <map>
//
//using namespace std;
//#define endl "\n"
//int N, M;
//int ans = 987654321;
//vector<pair<int, int>> shop;
//map<pair<int,int>, bool> picked;
//map<pair<int, int>, pair<int, int>> h_c;
//vector<vector<int>> g(53,vector<int>(53));
//
//int find(pair<int,int> h, pair<int,int>& c, int mode){ 
//	// mode 0은 초기에 집당 치킨거리찾기 상황이면 c에 처음부터 {-1,-1}넣어주기
//	int ret = 987654321; // 가장가까운 치킨거리
//	if (mode == 0) {
//		for (int i = 0; i < shop.size(); i++)
//		{
//			int tmp = ret;
//			int dis = abs(h.first - shop[i].first) + abs(h.second - shop[i].second);
//			ret = min(dis, ret);
//			if (tmp != ret) {
//				c.first = shop[i].first;
//				c.second = shop[i].second;
//			}
//		}
//	}
//	else {
//		for (auto p : picked) {
//			if (p.second) {
//				int tmp = ret;
//				ret = min(abs(h.first - p.first.first) + abs(h.second - p.first.second), ret);
//				if (tmp != ret) {
//					c.first = p.first.first;
//					c.second = p.first.second;
//				}
//			}
//		}
//	}
//	return ret;
//}
//
//
//
//
//void cal() {
//	int tmp = 0;
//	for (auto m : h_c) {
//		int dis = abs(m.first.first - m.second.first) + abs(m.first.second - m.second.second);
//		if (!picked[m.second]) {
//			pair<int, int> home = m.first;
//			pair<int, int> next_c = m.second;
//			dis = find(home, next_c, 1);
//		}
//		tmp += dis;
//	}
//	ans = min(ans, tmp);
//}
//
//
//
//void BT(int cnt, int idx) {
//	if (cnt == M) {
//		cal();
//		return;
//	}
//	for (int i = idx; i < (int)shop.size(); i++)
//	{
//		pair<int, int> now = shop[i];
//		picked[{now.first, now.second}] = true;
//		BT(cnt + 1, i + 1);
//		picked[{now.first, now.second}] = false;
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//
//	cin >> N >> M;
//	//집 당 최소 치킨집 계산하여 그 대상 알아내기 --> 맵에 저장 <집pair, 가장가까운치킨집pair>
//	/*vector<pair<int, int>> shop;
//	map<pair<int, int>, bool> picked;
//	map<pair<int, int>, pair<int, int>> h_c;*/
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			cin >> g[i][j];
//			if (g[i][j] == 1) {
//				h_c.insert({ {i, j }, {-1, -1} });
//			}
//			else if (g[i][j]) {
//				shop.push_back({ i,j });
//			}
//		}
//	}
//
//	for (auto m : h_c) {
//		find(m.first, m.second, 0);
//	}
//
//	BT(0,0);
//	cout << ans;
//
//	return 0;
//}