//#include <iostream>
//#include <algorithm>
//#include <map>
//#include <vector>
//
//using namespace std;
//#define endl "\n"
//int N, mp, mf, ms, mv;
//int m[5];
//
//int food[17][5];
//int p, f, s, v, c;
//int ans = 987654321;
//int total[5];
//vector<int> chosen;
//vector<int> ans_v;
//
//
//void BT(int cnt, int idx) {
//	int flag = 1;
//	if (cnt > 0) {
//		for (int i = 0; i < 4; i++)
//		{
//			if (total[i] < m[i]) {
//				flag = 0; break;
//			}
//		}
//		if (flag) { // 기준 영양분 만족함
//			if (total[4] < ans) {
//				ans = total[4];
//				ans_v = chosen;
//			}
//			return;
//		}
//	}
//
//	for (int i = idx; i < N; i++)
//	{
//		chosen.push_back(i);
//		for (int j = 0; j < 5; j++)
//		{
//			total[j] += food[i][j];
//		}
//		BT(cnt + 1, i + 1);
//		chosen.pop_back();
//		for (int j = 0; j < 5; j++)
//		{
//			total[j] -= food[i][j];
//		}
//	}
//
//
//
//}
//
//
//int main() {
//	cin >> N;
//	cin >> m[0] >> m[1] >> m[2] >> m[3];
//	for (int i = 0; i < N; i++)
//	{
//		cin >> food[i][0] >> food[i][1] >> food[i][2] >> food[i][3] >> food[i][4];
//	}
//
//	
//	BT(0, 0);
//	if (ans_v.empty())cout << -1;
//	else {
//		cout << ans << endl;
//		sort(ans_v.begin(), ans_v.end());
//		for (auto i : ans_v)cout << i+1 << " ";
//	}
//
//
//	return 0;
//}